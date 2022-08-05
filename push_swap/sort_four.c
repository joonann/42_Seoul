/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:30:54 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:30:55 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_four(t_info *info)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = info->a_top;
	i = 0;
	min = tmp->cont;
	while (i < 3)
	{
		if (min > tmp->next->cont)
			min = tmp->next->cont;
		tmp = tmp->next;
		i++;
	}
	return (min);
}

void	sort_only_four_a(t_info *info)
{
	int	min;

	min = min_four(info);
	while (info->a_top->cont != min)
		ra(info);
	pb(info);
	sort_only_three_a(info);
	pa(info);
}

void	sort_four_a(t_info *info)
{
	int	r_a;
	int	i;

	if (check_sorted_a(info, 4))
		return ;
	r_a = 0;
	pb(info);
	sort_three_a(info);
	i = 0;
	while (info->a_top->cont < info->b_top->cont && i < 3)
	{
		ra(info);
		r_a++;
		i++;
	}
	pa(info);
	while (r_a--)
		rra(info);
}

void	sort_four_b(t_info *info)
{
	int	r_b;
	int	i;

	if (check_sorted_b(info, 4))
		return ;
	r_b = 0;
	pa(info);
	sort_three_b(info);
	i = 0;
	while (info->a_top->cont < info->b_top->cont && i < 3)
	{
		rb(info);
		r_b++;
		i++;
	}
	pb(info);
	while (r_b--)
		rrb(info);
}
