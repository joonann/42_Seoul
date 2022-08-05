#include "push_swap.h"

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