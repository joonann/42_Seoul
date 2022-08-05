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