/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:42 by junhkim           #+#    #+#             */
/*   Updated: 2022/04/05 14:15:14 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_gnl_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (c == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_gnl_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}

char	*ft_gnl_strjoin(char *backup, char *str)
{
	char	*new;
	int		b_len;
	int		s_len;

	if (!backup)
	{
		backup = (char *)malloc(sizeof(char) * 1);
		if (!backup)
			return (NULL);
		backup[0] = '\0';
	}
	b_len = ft_gnl_strlen(backup);
	s_len = ft_gnl_strlen(str);
	new = (char *)malloc(sizeof(char) * (b_len + s_len + 1));
	if (!new)
	{
		free(backup);
		return (NULL);
	}
	ft_gnl_strncpy(new, backup, b_len);
	ft_gnl_strncpy(new + b_len, str, s_len);
	new[b_len + s_len] = '\0';
	free(backup);
	return (new);
}
