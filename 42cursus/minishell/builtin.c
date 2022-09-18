/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:13:45 by docho             #+#    #+#             */
/*   Updated: 2022/09/19 07:00:38 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char *env_name)
{
	char	*envptr;

	envptr = getenv(env_name);
	if (envptr)
		ft_putstr_fd(envptr, 1);
}

void	print_echo_char(char *argv)
{
	while (*argv)
	{
		if (*argv == '$')
		{
			if (*(argv + 1) == '?')
			{
				// exit code 매개변수로 받아서 출력
				argv += 2;
				continue ;
			}	
		}
		ft_putchar_fd(*argv, 1);
		argv++;
	}
}

void	print_echo(char **argv, int start)
{
	while (argv[start])
	{
		print_echo_char(argv[start]);
		start++;
		if (argv[start])
			write(1, " ", 1);
		else
			break ;
	}
}

void    echo(char **argv)
{
	if (!argv[1])
	{
		write(1, "\n", 1);
		return ;
	}
	if (ft_strcmp(argv[1], "-n"))
		print_echo(argv, 1);
	else
	{
		print_echo(argv, 1);
		write(1, "\n", 1);
	}
}

char *build_path(char **argv)
{
	char *result;
	if (!ft_strncmp(argv[1], "./", 2) || !ft_strncmp(argv[1], "../", 3)
		|| !ft_strncmp(argv[1], "/", 1))
		result = argv[1];
	else
		result = NULL;
	return (result);
}

void	change_env(char *path)
{
	
}

void    cd(char **argv)
{
	char *path;

	if (argv[2])
		ft_putstr_fd("bash: cd: too many arguments\n", 2);
	if (!argv[1])
		ft_putstr_fd("bash: cd: not a relative or absolute path\n", 2);
	path = build_path(argv);
	if (chdir(path) == 0)
	{
		change_env(path); //(PWD, OLDPWD바꿔줘야 된다 export 활용)
	}
	else
	{
		ft_putstr_fd("bash: cd: :", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("No such file or directory\n", 2);
	}
}

void	env(char **argv, char **envp)
{
	int	i;
	if (argv[1])
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("' : Permission Denied\n", 2);
		return ;
	}
	i = 0;
	while(envp[i++])
	{
		ft_putstr_fd(envp[i], 1);
		write(1, "\n", 1);
	}
}

void    pwd(char **argv)
{
	char	*buf;
	int		n;

	n = 1;
	while (1)
	{
		buf = (char *)malloc(n * 100 * sizeof(char));
		if (buf == NULL)
			terminate();
		if (getcwd(buf, n++ * 100) == NULL)
		{
			free(buf);
			if (errno == ERANGE)
				continue ;
			else
				terminate();
		}
		break ;
	}
	ft_putstr_fd(buf, 1);
	free(buf);
}

int	check_env_name(char *name)
{
	if (ft_isdigit(*name))
		return (0);
	while (*name)
	{
		if (!ft_isalnum(*name) && (*name != '_'))
			return (0);
		name++;
	}
	return (1);
}

void	print_unset_invalid(char *varname)
{
	ft_putstr_fd("bash: unset: `", 2);
	ft_putstr_fd(varname, 2);
	ft_putstr_fd("': not a valid identifier\n");
}

int	count_envp(char **envp)
{
	int	count;

	count = 0;
	while (envp[count])
		count++;
	return (count);
}

void	matrix_free(char **matrix, int index)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (i < index)
		free(matrix[i]);
	free(matrix);
}

char	**remove_one_var(char **envp, int index)
{
	int	i;
	int	count;
	char	**new;

	i = 0;
	count = count_envp(envp);
	new = (char **)malloc(sizeof(char *) * count);
	if (!new)
		return (envp);
	while (++i < count)
	{
		if (i == index)
			continue ;
		new[i] = ft_calloc(ft_strlen(envp[i]) + 1, sizeof(char));
		if (!new[i])
		{
			matrix_free(new, i);
			return (envp);
		}
		ft_strlcpy(new[i], envp[i], ft_strlen(envp[i]));
	}
	matrix_free(envp, count);
	return (new);
}

char	**unset_var(char *varname, char **envp)
{
	int		i;
	int		len;
	char	**new_envp;

	i = -1;
	len = ft_strlen(varname);
	while (envp[++i])
	{
		if (ft_strlen(envp[i]) <= len)
			continue ;
		if (!ft_strncmp(varname, envp[i], len) && envp[len] == '=')
			break ;
	}
	if (!envp[i])
		return (envp);
	else
		return (remove_one_var(envp, index));
}

void    unset(char **argv, char ***envp)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_env_name(argv[i]))
		{
			print_unset_invalid(argv[i]);
			continue ;
		}
		*envp = unset_var(argv[i], *envp);
		i++;
	}
}

void	exit_error_message(char *message, char *non_numeric)
{
	ft_putstr_fd("exit\nbash: exit: ", 2);
	if (non_numeric)
	{
		ft_putstr_fd(non_numeric, 2);
		ft_putstr_fd(" ", 2);
	}
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

int	is_all_digit(char *str)
{
	while (*str++)
	{
		if (!ft_isdigit(*str))
			return (0);
	}
	return (1);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit(char **argv)
{
	int	i;

	if (argv[2])
		exit_error_message("too many arguments", 0);
	else if (argv[1] && !is_all_digit(argv[1]))
		exit_error_message("numeric argument required", argv[1]);
	else if (argv[1])
	{
		i = ft_atoi(argv[1]);
		free_argv(argv);
		exit(i);
	}
	else
	{
		free_argv(argv);
		exit(0);
	}
}

void    export()
{
	while (*envp)
		printf("%s\n", *envp++);
}

bool	isbuiltin(char **argv, char **envp)
{
	if (ft_strcmp(argv[0], "echo"))
		echo(argv);
	else if (ft_strcmp(argv[0], "cd"))
		cd(argv);
	else if (ft_strcmp(argv[0], "pwd"))
		pwd(argv);
	else if (ft_strcmp(argv[0], "export"))
		export(argv, &envp);
	else if (ft_strcmp(argv[0], "unset"))
		unset(argv, &envp);
	else if (ft_strcmp(argv[0], "env"))
		env(argv, envp);
	else if (ft_strcmp(argv[0], "exit"))
		exit(argv);
	else
		return (false);
	return (true);
}