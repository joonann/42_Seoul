/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:25:25 by junhkim           #+#    #+#             */
/*   Updated: 2022/07/15 12:18:15 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file_io(char *filename, int inout)
{
	if (inout == INFD)
		return (open(filename, O_RDONLY));
	else
		return (open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}

void	px_redirection(char *cmd, char **envp)
{
	int		fd[2];
	int		pipe_ret;
	pid_t	pid;

	pipe_ret = pipe(fd);
	if (pipe_ret < 0)
		error_with_message(1, "pipe failed.");
	pid = fork();
	if (pid < 0)
		error_with_message(1, "fork failed.");
	if (pid == 0)
	{
		close(fd[INFD]);
		if (dup2(fd[OUTFD], STDOUT) == -1)
			error_with_message(1, "dup failed.");
		px_execve(cmd, envp);
	}
	else
	{
		close(fd[OUTFD]);
		if (dup2(fd[INFD], STDIN) == -1)
			error_with_message(1, "dup failed.");
	}
	waitpid(0, NULL, WNOHANG);
}

void	px_execve(char *cmd, char **envp)
{
	char	**cmd_split;
	char	*file_path;

	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		error_with_message(1, "cmd split failed");
	if (!access(cmd_split[0], F_OK))
		file_path = cmd_split[0];
	else
		file_path = make_path(cmd_split, envp);
	execve(file_path, cmd_split, envp);
	write(STDERR, "pipex: command not found: ", 26);
	write(STDERR, cmd_split[0], ft_strlen(cmd_split[0]));
	free_cmd_split(cmd_split);
	free(file_path);
	exit(127);
}

void	infile_nonexist(char **argv, char **envp)
{
	int	fd_out;

	write(STDERR, "pipex: no such file or directory: ", 34);
	write(STDERR, argv[1], ft_strlen(argv[1]));
	write(STDERR, "\n", 1);
	fd_out = open_file_io(argv[4], OUTFD);
	if (fd_out < 0)
		error_with_message(0, "open output file failed.");
	if (dup2(fd_out, STDOUT) == -1)
		error_with_message(0, "file descriptor dup2 failed.");
	if (dup2(fd_out, STDIN) == -1)
		error_with_message(0, "file descriptor dup2 failed.");
	px_execve(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (argc == 5)
	{
		if (access(argv[1], F_OK))
			infile_nonexist(argv, envp);
		fd_in = open_file_io(argv[1], INFD);
		if (fd_in < 0)
			error_with_message(0, "open input file failed.");
		fd_out = open_file_io(argv[4], OUTFD);
		if (fd_out < 0)
			error_with_message(0, "open output file failed.");
		if (dup2(fd_in, STDIN) == -1)
			error_with_message(1, "file descriptor dup2 failed.");
		if (dup2(fd_out, STDOUT) == -1)
			error_with_message(1, "file descriptor dup2 failed.");
		px_redirection(argv[2], envp);
		px_execve(argv[3], envp);
	}
	else
		error_with_message(1, "there must be 4 arguments.");
	return (1);
}
