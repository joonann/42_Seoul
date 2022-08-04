/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:48:29 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/03 08:29:43 by junhkim          ###   ########.fr       */
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
// from here
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

void    sort_three_b(t_info *info)
{
    int top;
    int mid;
    int bot;

	
    top = info->b_top->cont;
    mid = info->b_top->next->cont;
    bot = info->b_top->next->next->cont;
    if (mid > top && mid > bot && bot > top)
		rb(info);
    else if (top > mid && bot > mid && bot > top)
        rrb(info);
    else if (mid > bot && mid > top && top > bot)
        sb(info);
    else if (top > mid && bot > mid && top > bot)
    {
		rrb(info);
		sb(info);
	}
    else if (top < mid && mid < bot)
    {
        rb(info);
        sb(info);
    }
}


void	sort_four_a(t_info *info)
{
	while (info->a_top->cont != info->arr[0])
		ra(info);
	pb(info);
	sort_three_a(info);
	pa(info);
}

void	sort_four_b(t_info *info)
{
	while (info->b_top->cont != info->arr[3])
		rb(info);
	pa(info);
	sort_three_b(info);
	pb(info);
}

void    sort_five_a(t_info *info)
{
    int mid;
    int i;
    int check;

    mid = info->arr[2];
    i = 0;
    check = 0;
    while (check < 2)
    {
        if (info->a_top->cont < mid)
        {
            pb(info);
            check++;
        }
		else
        	ra(info);
        i++;
    }
    sort_three_a(info);
    if (info->b_top->cont < info->b_top->next->cont)
        sb(info);
    pa(info);
    pa(info);
}

void    sort_five_b(t_info *info)
{
    int mid;
    int i;
    int check;

    mid = info->arr[2];
    i = 0;
    check = 0;
    while (check < 2)
    {
        if (info->b_top->cont > mid)
        {
            pa(info);
            check++;
        }
		else
        	rb(info);
        i++;
    }
    sort_three_b(info);
    if (info->b_top->cont < info->b_top->next->cont)
        sa(info);
    pb(info);
    pb(info);
}

void	sort_under_five_a(t_info *info, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two_a(info);
	else if (size == 3)
		sort_three_a(info);
	else if (size == 4)
		sort_four_a(info);
	else if (size == 5)
		sort_five_a(info);
}

void	sort_under_five_b(t_info *info, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two_b(info);
	else if (size == 3)
		sort_three_b(info);
	else if (size == 4)
		sort_four_b(info);
	else if (size == 5)
		sort_five_b(info);
}

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

void	divide_loop_a(t_info *info, int *pv, int *r_a, int *r_b, int loop)
{
	int	tmp;

	while (loop--)
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
	}
}

void	divide_into_three_a(t_info *info, int start, int end)
{
	int	pv[2];
	int	loop;
	int	r_a;
	int	r_b;

	loop = end - start + 1;
	r_a = 0;
	r_b = 0;
	pv[0] = info->arr[start + ((end - start) * 1 / 3)];
	pv[1] = info->arr[start + ((end - start) * 2 / 3)];
	divide_loop_a(info, pv, &r_a, &r_b, loop);
	divide_rotate_back(info, r_a, r_b);
}

void	divide_loop_b(t_info *info, int *pv, int *r_a, int *r_b, int loop)
{
	int	tmp;

	while (loop--)
	{
		tmp = info->b_top->cont;
		if (tmp >= pv[1])
		{	
			pa(info);
			if (tmp < pv[0])
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
	}
}

void	divide_into_three_b(t_info *info, int start, int end)
{
	int	pv[2];
	int	loop;
	int	r_a;
	int	r_b;

	loop = end - start + 1;
	r_a = 0;
	r_b = 0;
	pv[0] = info->arr[start + ((end - start) * 1 / 3)];
	pv[1] = info->arr[start + ((end - start) * 2 / 3)];
	divide_loop_b(info, pv, &r_a, &r_b, loop);
	divide_rotate_back(info, r_a, r_b);
}

void	stack_sort(t_info *info)
{
	if (info->size <= 5)
		sort_under_five_a(info, info->size);
	else
	{
		divide_into_three_a(info, 0, 29);
		divide_into_three_a(info, 19, 29);
		divide_into_three_a(info, 25, 29);
		sort_under_five_a(info, info->a_size);
		sort_under_five_b(info, 2);
		pa(info);
		pa(info);
		divide_into_three_b(info, 19, 24);
		sort_under_five_a(info, 3);
		// sort_under_five_b(info, 3);
		// pa(info);
		// pa(info);
		// pa(info);
	}
}

// void	sort_four_a(t_info *info)
// {
// 	int	
// 	while ()
// 	{
// 		if (info->a_top->cont == info->arr[0])
// 			pa
// }

void	printing(t_info *info)
{
	t_node *tmp;

	printf("a_list : ");
	tmp = info->a_top;
	while (tmp)
	{
		printf("%d ", tmp->cont);
		tmp = tmp->next;
	}
	printf("\n");

	printf("b_list : ");
	tmp = info->b_top;
	while (tmp)
	{
		printf("%d ", tmp->cont);
		tmp = tmp->next;
	}
	printf("\n");
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
	
	printing(info);

	info_free(info);
	return (0);
}
