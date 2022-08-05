/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:48:44 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/05 10:09:00 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node {
	int	cont;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info {
	int	*arr;
	int	size;
	t_node	*a_top;
	t_node	*a_bot;
	t_node	*b_top;
	t_node	*b_bot;
	int	a_size;
	int	b_size;
}	t_info;

void	error_exit(int check);
void	stack_free(t_node *node);
void	info_free(t_info *info);
void	error_free(t_info *info, int check);
void	atoll_plus_minus_check(char *argv_str, int *index, t_info *info);
void	arr_size(int argc, char **argv, t_info *info);
long long	convert_int(char *str, int *index);
long long	ft_atoll(char *str, int *index);
long long	atoll_to_int(char *str, t_info *info, int *index);
t_node	*create_one_node(t_info *info);
t_info	*info_init(void);
void	arr_init(t_info *info);
void	argv_to_arr(t_info *info, char **argv);
void	ft_swap(int *a, int *b);
void	arr_bubble_sort(int *arr, t_info *info);
t_node	*first_node(t_info *info);
void	arr_to_stack(t_info *info);
int	main(int argc, char **argv);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa_2(t_info *info, t_node *tmp);
void	pa(t_info *info);
void	pb_2(t_info *info, t_node *tmp);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void    sort_five_a(t_info *info);
void    stack_sort(t_info *info);
int	check_sorted_a(t_info *info, int size);
int	check_sorted_b(t_info *info, int size);
void    sort_a_recurs(t_info *info, int start, int end);
void    sort_b_recurs(t_info *info, int start, int end);
void	sort_two_a(t_info *info);
void	sort_two_b(t_info *info);
void    sort_only_three_a(t_info *info);
void	sort_three_a_2(t_info *info);
void	sort_three_a_3(t_info *info);
void	sort_three_a_4(t_info *info);
void	sort_three_a_5(t_info *info);
void    sort_three_a(t_info *info);
void	sort_three_b_2(t_info *info);
void	sort_three_b_3(t_info *info);
void	sort_three_b_4(t_info *info);
void	sort_three_b_5(t_info *info);
void    sort_three_b(t_info *info);
int	min_four(t_info *info);
void	sort_only_four_a(t_info *info);
void	sort_four_a(t_info *info);
void	sort_four_b(t_info *info);
void	arr_five_bubble_sort(int *arr);
int	mid_five(t_info *info);
void    sort_only_five_a(t_info *info);
void	sort_five_a_2(t_info *info, int *r_a);
void	sort_five_a(t_info *info);
void	sort_five_b_2(t_info *info, int *r_b);
void	sort_five_b(t_info *info);
void	sort_only_under_five_a(t_info *info, int size);
void	sort_under_five_a(t_info *info, int size);
void	sort_under_five_b(t_info *info, int size);
void	divide_rotate_back(t_info *info, int r_a, int r_b);
void	divide_loop_a(t_info *info, int *pv, int *r_a, int *r_b, int loop);
void	divide_into_three_a(t_info *info, int start, int end);
void	divide_loop_b(t_info *info, int *pv, int *r_a, int *r_b, int loop);
void	divide_into_three_b(t_info *info, int start, int end);

#endif
