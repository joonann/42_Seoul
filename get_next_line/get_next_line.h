#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPEN_MAX 256

# include <stdlib.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	ft_strchr(char *str, char c);
void	ft_strncpy(char *dst, char *src, int n);
char	*ft_strjoin(char *backup, char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup, char *line);
char	*ft_read(char *backup, int fd);

#endif
