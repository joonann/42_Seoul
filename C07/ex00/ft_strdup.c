/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:57:50 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/28 09:57:52 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest_str;
	int		index;
	int		src_len;

	index = 0;
	while (src[index])
		index++;
	src_len = index;
	dest_str = malloc(sizeof(char) * (index + 1));
	if (!dest_str)
		return (0);
	index = 0;
	while (src[index])
	{
		dest_str[index] = src[index];
		index++;
	}
	dest_str[index] = 0;
	return (dest_str);
}
