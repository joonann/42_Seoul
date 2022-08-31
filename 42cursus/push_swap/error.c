/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:48:20 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 15:33:32 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(int check)
{
	if (check > 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		exit(1);
}

void	stack_free(t_node *node)
{
	t_node	*tmp;

	while (node->next)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(node);
}

void	info_free(t_info *info)
{
	if (info->a_top)
		stack_free(info->a_top);
	if (info->b_top)
		stack_free(info->b_top);
	if (info->arr)
		free(info->arr);
	if (info)
		free(info);
}

void	error_free(t_info *info, int check)
{
	info_free(info);

	error_exit(check);
}
