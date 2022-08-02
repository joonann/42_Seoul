/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sa_sb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:48:14 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/03 06:48:16 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->a_size < 2)
		return ;
	tmp = info->a_top->cont;
	info->a_top->cont = info->a_top->next->cont;
	info->a_top->next->cont = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->b_size < 2)
		return ;
	tmp = info->b_top->cont;
	info->b_top->cont = info->b_top->next->cont;
	info->b_top->next->cont = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	tmp;

	if (info->a_size < 2 || info->b_size < 2)
		return ;
	tmp = info->a_top->cont;
	info->a_top->cont = info->a_top->next->cont;
	info->a_top->next->cont = tmp;
	tmp = info->b_top->cont;
	info->b_top->cont = info->b_top->next->cont;
	info->b_top->next->cont = tmp;
	write(1, "ss\n", 3);
}
