#include "push_swap.h"

void	rra(t_info *info)
{
	t_node	*tmp;

	if (info->a_size < 2)
		return ;
	tmp = info->a_bot;
	info->a_bot = info->a_bot->prev;
	info->a_bot->next = NULL;
	info->a_top->prev = tmp;
	tmp->next = info->a_top;
	info->a_top = tmp;
	info->a_top->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_node	*tmp;

	if (info->b_size < 2)
		return ;
	tmp = info->b_bot;
	info->b_bot = info->b_bot->prev;
	info->b_bot->next = NULL;
	info->b_top->prev = tmp;
	tmp->next = info->b_top;
	info->b_top = tmp;
	info->b_top->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_node	*tmp;

	if (info->a_size < 2 || info->b_size < 2)
		return ;
	tmp = info->a_bot;
	info->a_bot = info->a_bot->prev;
	info->a_bot->next = NULL;
	info->a_top->prev = tmp;
	tmp->next = info->a_top;
	info->a_top = tmp;
	info->a_top->prev = NULL;
	tmp = info->b_bot;
	info->b_bot = info->b_bot->prev;
	info->b_bot->next = NULL;
	info->b_top->prev = tmp;
	tmp->next = info->b_top;
	info->b_top = tmp;
	info->b_top->prev = NULL;
	write(1, "rrr\n", 4);
}