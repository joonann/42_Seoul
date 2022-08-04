#include "push_swap.h"

int	get_index(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (num == arr[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_sorted_a(t_info *info, int size)
{
	t_node	*tmp;
	int		a;
	int		i;
	int		j;

	tmp = info->a_top;
	a = tmp->cont;
	i = get_index(info->arr, a);
	j = 1;
	while (j < size && i <= info->size)
	{
		tmp = tmp->next;
		a = tmp->cont;
		i++;
		if (a != info->arr[i])
			return (0);
		j++;
	}
	if (j != size)
		return (0);
	return (1);
}

int	check_sorted_b(t_info *info, int size)
{
	t_node	*tmp;
	int		a;
	int		i;
	int		j;

	tmp = info->b_top;
	a = tmp->cont;
	i = get_index(info->arr, a);
	j = 1;
	while (j < size && i >= 0)
	{
		tmp = tmp->next;
		a = tmp->cont;
		i--;
		if (a != info->arr[i])
			return (0);
		j++;
	}
	if (j != size)
		return (0);
	return (1);
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