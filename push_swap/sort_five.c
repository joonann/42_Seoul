/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:30:35 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:30:37 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_a_2(t_info *info, int *r_a)
{
	int	i;

	i = 0;
	if (info->b_top->cont < info->b_top->next->cont)
		sb(info);
	while (info->a_top->cont < info->b_top->cont && i < 3)
	{
		ra(info);
		(*r_a)++;
		i++;
	}
}

void	sort_five_a(t_info *info)
{
	int	r_a;
	int	p_b;

	if (check_sorted_a(info, 5))
		return ;
	r_a = 0;
	pb(info);
	pb(info);
	p_b = 1;
	sort_three_a(info);
	sort_five_a_2(info, &r_a);
	pa(info);
	while (r_a--)
	{
		if (info->a_bot->cont < info->b_top->cont)
		{
			pa(info);
			p_b--;
		}
		rra(info);
	}
	if (p_b)
		pa(info);
}

void	sort_five_b_2(t_info *info, int *r_b)
{
	int	i;

	i = 0;
	if (info->a_top->cont > info->a_top->next->cont)
		sa(info);
	while (info->a_top->cont < info->b_top->cont && i < 3)
	{
		rb(info);
		(*r_b)++;
		i++;
	}	
}

void	sort_five_b(t_info *info)
{
	int	r_b;
	int	p_a;

	if (check_sorted_b(info, 5))
		return ;
	r_b = 0;
	pa(info);
	pa(info);
	p_a = 1;
	sort_three_b(info);
	sort_five_b_2(info, &r_b);
	pb(info);
	while (r_b--)
	{
		if (info->a_top->cont < info->b_bot->cont)
		{
			pb(info);
			p_a--;
		}
		rrb(info);
	}
	if (p_a)
		pb(info);
}
