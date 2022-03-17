/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:59:06 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/28 09:59:25 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	whole_size(int size, char **strs, char *sep)
{
	int	count;
	int	loop1;
	int	loop2;

	count = 1;
	loop1 = 0;
	loop2 = 0;
	while (loop1 < size)
	{
		while (strs[loop1][loop2])
		{
			count++;
			loop2++;
		}
		loop2 = 0;
		loop1++;
	}
	if (size <= 1)
		return (count);
	while (sep[loop2])
		loop2++;
	count = count + (loop2 * (size - 1));
	return (count);
}

int	sep_insert(char *dest, char*sep, int index)
{
	int	loop;

	loop = 0;
	while (sep[loop])
	{
		dest[index] = sep[loop];
		loop++;
		index++;
	}
	return (index);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		index;
	int		loop;

	dest = malloc(sizeof(char) * whole_size(size, strs, sep));
	if (!dest)
		return (0);
	index = 0;
	loop = 0;
	while (loop < size)
	{
		while (*strs[loop])
		{
			dest[index] = *strs[loop];
			strs[loop] = strs[loop] + 1;
			index++;
		}
		if (loop + 1 < size)
			index = sep_insert(dest, sep, index);
		loop++;
	}
	dest[index] = '\0';
	return (dest);
}
