/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:30:45 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:38:54 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_five_bubble_sort(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = i + 1;
		while (j < 5)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

int	mid_five(t_info *info)
{
	int	arr[5];

	arr[0] = info->a_top->cont;
	arr[1] = info->a_top->next->cont;
	arr[2] = info->a_top->next->next->cont;
	arr[3] = info->a_top->next->next->next->cont;
	arr[4] = info->a_top->next->next->next->next->cont;
	arr_five_bubble_sort(arr);
	return (arr[2]);
}

void	sort_only_five_a(t_info *info)
{
	int	mid;
	int	i;
	int	check;

	mid = mid_five(info);
	i = 0;
	check = 0;
	while (check < 2 && i < 5)
	{
		if (info->a_top->cont < mid)
		{
			pb(info);
			check++;
		}
		else
			ra(info);
		i++;
	}
	sort_only_three_a(info);
	if (info->b_top->cont < info->b_top->next->cont)
		sb(info);
	pa(info);
	pa(info);
}
