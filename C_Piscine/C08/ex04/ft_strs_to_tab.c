/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:22:52 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/30 11:28:57 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dest_str;
	int		index;
	int		len;

	index = 0;
	len = str_len(src);
	dest_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest_str)
		return (0);
	while (src[index])
	{
		dest_str[index] = src[index];
		index++;
	}
	dest_str[index] = 0;
	return (dest_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s_stock;

	s_stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s_stock)
		return (NULL);
	i = 0;
	while (av[i] && i < ac)
	{
		s_stock[i].size = str_len(av[i]);
		s_stock[i].str = av[i];
		s_stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_stock[i].size = 0;
	s_stock[i].str = 0;
	s_stock[i].copy = 0;
	return (s_stock);
}
