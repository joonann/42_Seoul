void    stack_sort(t_info *info)
{
    if (info->size <= 5)
        sort_only_under_five_a(info, info->size);
    else
    {
        sort_a_recurs(info, 0, info->size - 1);
    }
}

void    sort_a_recurs(info, start, end)
{
    int size;
    int new_start_1;
    int new_start_2;

    size = end - start + 1;
    new_start_1 = start + (size * 1 / 3) - 1
    new_start_2 = start + (size * 2 / 3) - 1
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

void    sort_b_recurs(info, start, end)
{
    int size;
    int i;
    int new_start_1;

    i = 0;
    size = end - start + 1;
    new_start_1 = start + (size * 1 / 3) - 1
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













        divide_into_three_a(info, 0, 29);
		divide_into_three_a(info, 19, 29);
		divide_into_three_a(info, 25, 29);
		sort_under_five_a(info, info->a_size);
		sort_under_five_b(info, 2);
		pa(info);
		pa(info);
		divide_into_three_b(info, 19, 24);
		sort_under_five_a(info, 3);
		sort_under_five_b(info, 3);
		pa(info);
		pa(info);
		pa(info);
		divide_into_three_b(info, 9, 18);
		sort_under_five_a(info, 4);
		divide_into_three_b(info, 9, 14);
		sort_under_five_a(info, 3);
		sort_under_five_b(info, 3);
		pa(info);
		pa(info);
		pa(info);
		divide_into_three_b(info, 0, 8);
		sort_under_five_a(info, 1);
		sort_under_five_b(info, 5);
		pa(info);
		pa(info);
		pa(info);
		pa(info);
		pa(info);
		