/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:58:52 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/28 09:58:59 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	rang_size;
	int	index;

	rang_size = max - min;
	index = 0;
	if (rang_size <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * rang_size);
	if (!*range)
		return (-1);
	while (index < rang_size)
	{
		(*range)[index] = min;
		index++;
		min++;
	}
	return (rang_size);
}
