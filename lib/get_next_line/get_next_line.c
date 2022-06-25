/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:02 by junhkim           #+#    #+#             */
/*   Updated: 2022/04/05 15:59:14 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *backup)
{
	char	*line;
	int		len;
	int		size;

	len = 0;
	if (!backup)
		return (NULL);
	if (!backup[len])
		return (NULL);
	while (backup[len] && backup[len] != '\n')
		len++;
	if (backup[len] == '\n')
	size = len + 2;
	else
		size = len + 1;
	line = (char *)malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	ft_gnl_strncpy(line, backup, size - 1);
	line[size - 1] = '\0';
	return (line);
}

char	*ft_backup(char *backup, char *line)
{
	char	*tmp;
	int		len;
	int		i;

	if (!backup || !line)
	{
		free(backup);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	len = ft_gnl_strlen(backup + i);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
	{
		free(backup);
		return (NULL);
	}
	ft_gnl_strncpy(tmp, backup + i, len);
	tmp[len] = '\0';
	free(backup);
	return (tmp);
}

char	*ft_read(char *backup, int fd)
{
	char	*str;
	int		read_success;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	read_success = 1;
	while (read_success && ft_gnl_strchr(backup, '\n') != 1)
	{
		read_success = read(fd, str, BUFFER_SIZE);
		if (read_success == -1)
		{
			free(str);
			return (NULL);
		}
		str[read_success] = '\0';
		backup = ft_gnl_strjoin(backup, str);
	}
	free(str);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	backup[fd] = ft_read(backup[fd], fd);
	if (!backup[fd])
	{
		free(backup[fd]);
		return (NULL);
	}
	result = ft_get_line(backup[fd]);
	backup[fd] = ft_backup(backup[fd], result);
	if (!result || !backup[fd])
	{
		free(result);
		free(backup[fd]);
		return (NULL);
	}
	return (result);
}
