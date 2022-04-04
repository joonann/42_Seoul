#include "get_next_line.h"

char	*ft_get_line(char *backup)
{
	char	*line;
	int	len;
	int	size;

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
	ft_strncpy(line, backup, size - 1);
	line[size - 1] = '\0';
	return (line);
}

char	*ft_backup(char *backup, char *line)
{
	char	*tmp;
	int	len;
	int	i;

	if (!backup || !line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	len = ft_strlen(backup + i);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
	{
		free(backup);
		return (NULL);
	}
	ft_strncpy(tmp, backup + i, len + 1);
	free(backup);
	return (tmp);
}

char	*ft_read(char *backup, int fd)
{
	char	*str;
	int	read_success;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
	{
		free(backup);
		return (NULL);
	}
	read_success = 1;
	while (read_success && ft_strchr(backup, '\n') != 1)
	{
		read_success = read(fd, str, BUFFER_SIZE);
		if (read_success == -1)
		{
			free(str);
			return (NULL);
		}
		str[read_success] = '\0';
		backup = ft_strjoin(backup, str);
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
	if (!backup[fd])
	{
		backup[fd] = (char *)malloc(sizeof(char) * 1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = '\0';
	}
	backup[fd] = ft_read(backup[fd], fd);
	result = ft_get_line(backup[fd]);
	backup[fd] = ft_backup(backup[fd], result);
	if (!result || !backup[fd])
	{
		free(backup[fd]);
		return (NULL);
	}
	return (result);
}
