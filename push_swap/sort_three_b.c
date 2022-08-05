/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:31:11 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:35:23 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b_2(t_info *info)
{
	pa(info);
	pa(info);
	rb(info);
	sa(info);
	pb(info);
	pb(info);
	rrb(info);
}

void	sort_three_b_3(t_info *info)
{
	rb(info);
	pa(info);
	rrb(info);
	sb(info);
	pb(info);
}

void	sort_three_b_4(t_info *info)
{
	pa(info);
	sb(info);
	rb(info);
	pb(info);
	rrb(info);
}

void	sort_three_b_5(t_info *info)
{
	pa(info);
	sb(info);
	pb(info);
}

void	sort_three_b(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->b_top->cont;
	mid = info->b_top->next->cont;
	bot = info->b_top->next->next->cont;
	if (top < mid && mid < bot)
		sort_three_b_2(info);
	else if (mid > top && mid > bot && bot > top)
		sort_three_b_3(info);
	else if (top > mid && bot > mid && bot > top)
		sort_three_b_4(info);
	else if (mid > bot && mid > top && top > bot)
		sb(info);
	else if (top > mid && bot > mid && top > bot)
		sort_three_b_5(info);
}
