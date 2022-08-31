/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:54:07 by junhkim           #+#    #+#             */
/*   Updated: 2022/07/14 21:27:13 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

# define INFD 0
# define OUTFD 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		open_file_io(char *filename, int inout);
void	px_redirection(char *cmd, char **envp);
void	px_execve(char *cmd, char **envp);

void	error_with_message(int exitcode, char *message);
void	error_and_free(int exitcode, char *message, char **cmd_split);
void	free_cmd_split(char **cmd_split);

char	*find_path(char **envp, char **cmd);
char	*ft_file_path(char **cmd, char *path_line, int i);
char	*make_path(char **cmd, char **envp);
char	*px_substr_plus_slash(char *str, int i, int len);

#endif
