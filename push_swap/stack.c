#include "push_swap.h"

t_node	*create_one_node(t_info *info)
{
	t_node	*tmp;

	tmp = NULL;
	tmp = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!tmp)
		error_free(info, 1);
	return (tmp);
}

t_node	*first_node(t_info *info)
{
	t_node	*tmp;

	tmp = create_one_node(info);
	tmp->cont = info->arr[0];
	tmp->next = NULL;
	return (tmp);
}

void	arr_to_stack(t_info *info)
{
	int	i;
	t_node	*new;

	i = 0;
	while (i < info->size)
	{
		new = create_one_node(info);
		(info->a_size)++;
		info->a_bot->cont = info->arr[i];
		info->a_bot->next = new;
		new->prev = info->a_bot;
		info->a_bot = new;
		i++;
	}
	info->a_bot = info->a_bot->prev;
	free(new);
	info->a_bot->next = NULL;
}