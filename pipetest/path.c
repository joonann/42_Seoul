/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:59 by junhkim           #+#    #+#             */
/*   Updated: 2022/07/14 21:31:12 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, char **cmd)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	error_and_free(127, "command not found: ", cmd);
	return (0);
}

char	*px_substr_plus_slash(char *str, int i, int len)
{
	char	*temp;
	int		j;

	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	j = 0;
	while (j < len)
	{
		temp[j] = str[i];
		j++;
		i++;
	}
	temp[j] = 47;
	temp[j + 1] = '\0';
	return (temp);
}

char	*ft_file_path(char **cmd, char *path_line, int i)
{
	int		j;
	char	*dir;
	char	*file_path;

	while (path_line[i] != '\0' && path_line[i] != '\n')
	{
		j = 0;
		while (path_line[i + j] != ':' && path_line[i + j] != '\0')
			j++;
		dir = px_substr_plus_slash(path_line, i, j);
		if (!dir)
			error_and_free(1, "ft_substr failed: ", cmd);
		file_path = ft_strjoin(dir, cmd[0]);
		if (!file_path)
			error_and_free(1, "ft_strjoin faile: ", cmd);
		free(dir);
		if (!access(file_path, F_OK))
			return (file_path);
		i = i + j;
		if (!path_line[i])
			break ;
		i++;
	}
	return (0);
}

char	*make_path(char **cmd, char **envp)
{
	char	*path_line;
	char	*file_path;

	path_line = find_path(envp, cmd);
	file_path = ft_file_path(cmd, path_line, 5);
	if (!file_path)
	{
		error_and_free(127, "command not found: ", cmd);
	}
	return (file_path);
}
