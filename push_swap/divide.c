/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:27:56 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 11:15:15 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_rotate_back(t_info *info, int r_a, int r_b)
{
	while (r_a > 0 && r_b > 0)
	{
		rrr(info);
		r_a--;
		r_b--;
	}
	while (r_a > 0)
	{	
		rra(info);
		r_a--;
	}
	while (r_b)
	{
		rrb(info);
		r_b--;
	}
}

void	divide_loop_a(t_info *info, int *pv, int *r_a, int *r_b)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < pv[2])
	{
		tmp = info->a_top->cont;
		if (tmp < pv[1])
		{	
			pb(info);
			if (tmp >= pv[0])
			{
				rb(info);
				(*r_b)++;
			}
		}
		else
		{
			ra(info);
			(*r_a)++;
		}
		i++;
	}
}

void	divide_into_three_a(t_info *info, int start, int end)
{
	int	pv[3];
	int	r_a;
	int	r_b;

	pv[2] = end - start + 1;
	r_a = 0;
	r_b = 0;
	pv[0] = info->arr[start + (pv[2] / 3)];
	pv[1] = info->arr[start + (pv[2] / 3 * 2)];
	divide_loop_a(info, pv, &r_a, &r_b);
	divide_rotate_back(info, r_a, r_b);
}

void	divide_loop_b(t_info *info, int *pv, int *r_a, int *r_b)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < pv[2])
	{
		tmp = info->b_top->cont;
		if (tmp >= pv[0])
		{	
			pa(info);
			if (tmp < pv[1])
			{
				ra(info);
				(*r_a)++;
			}
		}
		else
		{
			rb(info);
			(*r_b)++;
		}
		i++;
	}
}

void	divide_into_three_b(t_info *info, int start, int end)
{
	int	pv[3];
	int	r_a;
	int	r_b;

	pv[2] = end - start + 1;
	r_a = 0;
	r_b = 0;
	pv[0] = info->arr[start + (pv[2] / 3)];
	pv[1] = info->arr[start + (pv[2] / 3 * 2)];
	divide_loop_b(info, pv, &r_a, &r_b);
	divide_rotate_back(info, r_a, r_b);
}
