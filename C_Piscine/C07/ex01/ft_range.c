/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:58:18 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/28 09:58:33 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	arr_len;
	int	*int_arr;
	int	index;

	arr_len = max - min;
	if (max - min <= 0)
		return (NULL);
	int_arr = malloc(sizeof(int) * arr_len);
	if (!int_arr)
		return (NULL);
	index = 0;
	while (index < arr_len)
	{
		int_arr[index] = min;
		index++;
		min++;
	}
	return (int_arr);
}
