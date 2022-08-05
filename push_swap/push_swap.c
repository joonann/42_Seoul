/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:48:29 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 11:07:59 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*info_init(void)
{
	t_info	*info;

	info = NULL;
	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		error_exit(1);
	info->a_top = create_one_node(info);
	info->a_bot = info->a_top;
	return (info);
}

void	arr_init(t_info *info)
{
	info->arr = (int *)ft_calloc(info->size, sizeof(int));
	if (!info->arr)
		error_free(info, 1);
}

void	stack_sort(t_info *info)
{
	if (info->size <= 5)
		sort_only_under_five_a(info, info->size);
	else
	{
		sort_a_recurs(info, 0, info->size - 1);
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = info_init();
	arr_size(argc, argv, info);
	argv_to_arr(info, argv);
	arr_to_stack(info);
	arr_bubble_sort(info->arr, info);
	stack_sort(info);
	info_free(info);
	return (0);
}
