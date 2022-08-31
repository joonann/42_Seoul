/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_arr_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:47:33 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/03 06:47:34 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_to_arr(t_info *info, char **argv)
{
	int	i;
	int	j;
	int	arr_index;

	arr_init(info);
	i = 1;
	arr_index = 0;
	while (argv[i])
	{
		if (!ft_strncmp(argv[i], " ", 2))
			error_free(info, 1);
		j = 0;
		while (argv[i][j])
		{
			info->arr[arr_index] = atoll_to_int(argv[i], info, &j);
			arr_index++;
		}
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	arr_bubble_sort(int *arr, t_info *info)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (i < info->size)
	{
		j = i + 1;
		while (j < info->size)
		{
			if (arr[i] == arr[j])
				error_free(info, 1);
			if (arr[i] > arr[j])
			{
				ft_swap(&arr[i], &arr[j]);
				check = 1;
			}
			j++;
		}
		i++;
	}
	if (check == 0)
		error_free(info, 0);
}
