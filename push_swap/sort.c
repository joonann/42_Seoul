#include "push_swap.h"
#include <stdio.h>

void    sort_three_a(t_info *info)
{
    int top;
    int mid;
    int bot;

    top = info->a_top->cont;
    mid = info->a_top->next->cont;
    bot = info->a_top->next->next->cont;
    if (top > mid && mid > bot && top > bot)
    {
        sa(info);
        rra(info);
    }
    else if (top > mid && mid > bot && bot > top)
    {
        sa(info);
        ra(info);
    }
    else if (top > mid && bot > mid && top > bot)
        ra(info);
    else if (top > mid && bot > mid && bot > top)
        sa(info);
    else if (mid > bot && mid > top && top > bot)
        rra(info);
}

void    sort_five(t_info *info)
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
        ra(info);
        printf("a_top : %d\n", info->a_top->cont);
        i++;
    }
    sort_three_a(info);
    if (info->b_top->cont < info->b_top->next->cont)
        sb(info);
    pa(info);
    pa(info);
}

void    stack_sort(t_info *info)
{
    if (info->size == 2)
        sa(info);
    else if (info->size == 3)
        sort_three_a(info);
    else if (info->size == 5)
        sort_five(info);
    else
        error_free(info, 1);
}