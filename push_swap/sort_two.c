/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:31:18 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:34:02 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_info *info)
{
	if (info->a_top->cont > info->a_top->next->cont)
		sa(info);
}

void	sort_two_b(t_info *info)
{
	if (info->b_top->cont < info->b_top->next->cont)
		sb(info);
}

void	sort_only_three_a(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a_top->cont;
	mid = info->a_top->next->cont;
	bot = info->a_top->next->next->cont;
	if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > bot && mid > top && top > bot)
		rra(info);
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
}
