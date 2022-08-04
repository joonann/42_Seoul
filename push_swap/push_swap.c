/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:48:29 by junhkim           #+#    #+#             */
/*   Updated: 2022/08/04 21:23:48 by junhkim          ###   ########.fr       */
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

void    sort_only_three_a(t_info *info)
{
    int top;
    int mid;
    int bot;

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

void    sort_three_a(t_info *info)
{
    int top;
    int mid;
    int bot;

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
	else if (top > mid && mid > bot && top > bot)
		sort_three_a_5(info);
}

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
	pa(info);
	rb(info);
	pa(info);
	rrb(info);
	pb(info);
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

void    sort_three_b(t_info *info)
{
    int top;
    int mid;
    int bot;

	
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

void	sort_only_four_a(t_info *info)
{
	while (info->a_top->cont != info->arr[0])
		ra(info);
	pb(info);
	sort_only_three_a(info);
	pa(info);
}

void	sort_four_a(t_info *info)
{
	int	r_a;

	if (check_sorted_a(info, 4))
		return ;
	r_a = 0;
	pb(info);
	sort_three_a(info);
	while (info->a_top->cont < info->b_top->cont)
	{
		ra(info);
		r_a++;
	}
	pa(info);
	while (r_a--)
		rra(info);
}

void	sort_four_b(t_info *info)
{
	int	r_b;

	if (check_sorted_b(info, 4))
		return ;
	r_b = 0;
	pa(info);
	sort_three_b(info);
	while (info->a_top->cont > info->b_top->cont)
	{
		rb(info);
		r_b++;
	}
	pa(info);
	while (r_b--)
		rrb(info);
}

void    sort_only_five_a(t_info *info)
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
    sort_only_three_a(info);
    if (info->b_top->cont < info->b_top->next->cont)
        sb(info);
    pa(info);
    pa(info);
}

void	sort_five_a_2(t_info *info, int *r_a)
{
	int	i;

	i = 0;
	if (info->b_top->cont < info->b_top->next->cont)
		sb(info);
	while (info->a_top->cont < info->b_top->cont && i < 3)
	{
		ra(info);
		(*r_a)++;
		i++;
	}
}

void	sort_five_a(t_info *info)
{
	int	r_a;
	int	p_b;

	if (check_sorted_a(info, 5))
		return ;
	r_a = 0;
	pb(info);
	pb(info);
	p_b = 1;
	sort_three_a(info);
	sort_five_a_2(info, &r_a);
	pa(info);
	while (r_a--)
	{
		if (info->a_bot->cont < info->b_top->cont)
		{
			pa(info);
			p_b--;
		}
		rra(info);
	}
	if (p_b)
		pa(info);
}

void	sort_five_b_2(t_info *info, int *r_b)
{
	int	i;

	i = 0;
	if (info->a_top->cont > info->a_top->next->cont)
		sa(info);
	while (info->a_top->cont < info->b_top->cont && i < 3)
	{
		rb(info);
		(*r_b)++;
		i++;
	}	
}

void	sort_five_b(t_info *info)
{
	int	r_b;
	int	p_a;

	if (check_sorted_b(info, 5))
		return ;
	r_b = 0;
	pa(info);
	pa(info);
	p_a = 1;
	sort_three_b(info);
	sort_five_b_2(info, &r_b);
	pb(info);
	while (r_b--)
	{
		if (info->a_top->cont < info->b_bot->cont)
		{
			pb(info);
			p_a--;
		}
		rrb(info);
	}
	if (p_a)
		pb(info);
}

void	sort_only_under_five_a(t_info *info, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two_a(info);
	else if (size == 3)
		sort_only_three_a(info);
	else if (size == 4)
		sort_only_four_a(info);
	else if (size == 5)
		sort_only_five_a(info);
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

void    sort_a_recurs(t_info *info, int start, int end)
{
    int size;
    int new_start_1;
    int new_start_2;

    size = end - start + 1;
    new_start_1 = start + (size * 1 / 3);
    new_start_2 = start + (size * 2 / 3);
    if (check_sorted_a(info, size))
        return ;
    if (size <= 5)
    {
        sort_under_five_a(info, size);
        return ;
    }
    divide_into_three_a(info, start, end);
    sort_a_recurs(info, new_start_2, end);
    sort_b_recurs(info, new_start_1, new_start_2 - 1);
    sort_b_recurs(info, start, new_start_1 - 1);
}

void    sort_b_recurs(t_info *info, int start, int end)
{
    int size;
    int i;
    int new_start_1;

    i = 0;
    size = end - start + 1;
    new_start_1 = start + (size * 1 / 3);
    if (size <= 5)
    {
        if (!check_sorted_b(info, size))
            sort_under_five_b(info, size);
        while (i < size)
        {
            pa(info);
            i++;
        }
        return  ;    
    }
    divide_into_three_b(info, start, end);
    sort_a_recurs(info, new_start_1, end);
    sort_b_recurs(info, start, new_start_1 - 1);
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

// ㅈㅣ워
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
