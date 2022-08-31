/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:31:03 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:36:48 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_2(t_info *info)
{
	pb(info);
	sa(info);
	pa(info);
}

void	sort_three_a_3(t_info *info)
{
	ra(info);
	ra(info);
	pb(info);
	rra(info);
	rra(info);
	pa(info);
}

void	sort_three_a_4(t_info *info)
{
	pb(info);
	ra(info);
	ra(info);
	pa(info);
	rra(info);
	rra(info);
}

void	sort_three_a_5(t_info *info)
{
	ra(info);
	pb(info);
	pb(info);
	sb(info);
	rra(info);
	pa(info);
	pa(info);
}

void	sort_three_a(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a_top->cont;
	mid = info->a_top->next->cont;
	bot = info->a_top->next->next->cont;
	if (mid > top && mid > bot && bot > top)
		sort_three_a_2(info);
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > bot && mid > top && top > bot)
		sort_three_a_3(info);
	else if (top > mid && bot > mid && top > bot)
		sort_three_a_4(info);
	else if (top > mid && mid > bot)
		sort_three_a_5(info);
}
