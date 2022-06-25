/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:12 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/25 22:46:02 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPEN_MAX 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_gnl_strlen(char *str);
int		ft_gnl_strchr(char *str, char c);
void	ft_gnl_strncpy(char *dst, char *src, int n);
char	*ft_gnl_strjoin(char *backup, char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup, char *line);
char	*ft_read(char *backup, int fd);

#endif
