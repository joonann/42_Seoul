/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:55:33 by junhkim           #+#    #+#             */
/*   Updated: 2022/07/14 22:31:55 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_with_message(int exitcode, char *message)
{
	write(STDERR, "pipex: ", 7);
	write(STDERR, message, ft_strlen(message));
	write(STDERR, "\n", 1);
	exit(exitcode);
}

void	error_and_free(int exitcode, char *message, char **cmd_split)
{
	write(STDERR, "pipex: ", 7);
	write(STDERR, message, ft_strlen(message));
	write(STDERR, cmd_split[0], ft_strlen(cmd_split[0]));
	free_cmd_split(cmd_split);
	write(STDERR, "\n", 1);
	exit(exitcode);
}

void	free_cmd_split(char **cmd_split)
{
	int	index;

	index = 0;
	while (cmd_split[index])
	{
		free(cmd_split[index]);
		index++;
	}
	free(cmd_split);
}
