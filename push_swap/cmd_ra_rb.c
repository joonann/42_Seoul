/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ra_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:47:53 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/03 06:47:54 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*tmp;

	if (info->a_size < 2)
		return ;
	tmp = info->a_top;
	info->a_top = info->a_top->next;
	info->a_top->prev = NULL;
	info->a_bot->next = tmp;
	tmp->prev = info->a_bot;
	info->a_bot = tmp;
	info->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_node	*tmp;

	if (info->b_size < 2)
		return ;
	tmp = info->b_top;
	info->b_top = info->b_top->next;
	info->b_top->prev = NULL;
	info->b_bot->next = tmp;
	tmp->prev = info->b_bot;
	info->b_bot = tmp;
	info->b_bot->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_node	*tmp;

	if (info->a_size < 2 || info->b_size < 2)
		return ;
	tmp = info->a_top;
	info->a_top = info->a_top->next;
	info->a_top->prev = NULL;
	info->a_bot->next = tmp;
	tmp->prev = info->a_bot;
	info->a_bot = tmp;
	info->a_bot->next = NULL;
	tmp = info->b_top;
	info->b_top = info->b_top->next;
	info->b_top->prev = NULL;
	info->b_bot->next = tmp;
	tmp->prev = info->b_bot;
	info->b_bot = tmp;
	info->b_bot->next = NULL;
	write(1, "rr\n", 3);
}
