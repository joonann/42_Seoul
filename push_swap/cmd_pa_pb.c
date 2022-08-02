#include "push_swap.h"

void	pa_2(t_info *info, t_node *tmp)
{
	if (info->b_size == info->size)
		{
			info->b_top = info->b_top->next;
			info->b_top->prev = NULL;
			info->a_top = tmp;
			info->a_bot = tmp;
			tmp->prev = NULL;
			tmp->next = NULL;
		}
		else
		{
			info->b_top = info->b_top->next;
			info->b_top = NULL;
			info->a_top->prev =tmp;
			tmp->next = info->a_top;
			info->a_top = tmp;
		}
}

void	pa(t_info *info)
{
	t_node	*tmp;

	if (info->b_size < 1)
		return ;
	tmp = info->b_top;
	if (info->b_size == 1)
	{
		tmp->prev = NULL;
		tmp->next = info->a_top;
		info->a_top->prev = tmp;
		info->a_top = tmp;
		info->b_top = NULL;
		info->b_bot = NULL;
	}
	if (info->b_size > 1)
		pa_2(info, tmp);
	(info->a_size)++;
	(info->b_size)--;
	write(1, "pa\n", 3);
}

void	pb_2(t_info *info, t_node *tmp)
{
	if (info->a_size == info->size)
		{
			info->a_top = info->a_top->next;
			info->a_top->prev = NULL;
			info->b_top = tmp;
			info->b_bot = tmp;
			tmp->prev = NULL;
			tmp->next = NULL;
		}
		else
		{
			info->a_top = info->a_top->next;
			info->a_top = NULL;
			info->b_top->prev =tmp;
			tmp->next = info->b_top;
			info->b_top = tmp;
		}
}

void	pb(t_info *info)
{
	t_node	*tmp;

	if (info->a_size < 1)
		return ;
	tmp = info->a_top;
	if (info->a_size == 1)
	{
		tmp->prev = NULL;
		tmp->next = info->b_top;
		info->b_top->prev = tmp;
		info->b_top = tmp;
		info->a_top = NULL;
		info->a_bot = NULL;
	}
	if (info->a_size > 1)
		pb_2(info, tmp);
	(info->b_size)++;
	(info->a_size)--;
	write(1, "pb\n", 3);
}