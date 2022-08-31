/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:43:40 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/25 19:52:50 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index_1;
	unsigned int	index_2;

	index_1 = 0;
	index_2 = 0;
	if (str_len(dest) >= size)
		return (str_len(src) + size);
	while (dest[index_1])
		index_1++;
	while (src[index_2] && index_1 + 1 < size)
	{
		dest[index_1] = src[index_2];
		index_1++;
		index_2++;
	}
	dest[index_1] = 0;
	return (str_len(dest) + str_len(src));
}
