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

void    sort_a_recurs(t_info *info, int start, int end)
{
    int size;
    int new_start_1;
    int new_start_2;

    size = end - start + 1;
    new_start_1 = start + (size / 3);
    new_start_2 = start + (size / 3 * 2);
    if (check_sorted_a(info, size))
        return ;
    if (size <= 5)
    {
		if (size == info->a_size)
			sort_only_under_five_a(info, size);
        else
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
    new_start_1 = start + (size / 3);
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