/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 09:37:25 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/19 09:37:30 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_one(int n, int i, char *arr);

void	set_combn(int n, int field, char *arr)
{
	while (field < n)
	{
		arr[field + 1] = arr[field] + 1;
		field++;
	}
}

void	ft_print_combn2(int n, int field, char *arr)
{
	if (arr[0] > '9' + 1 - n && arr[n - 1] == '9' + 1)
		return ;
	set_combn(n, field, arr);
	if (arr[field] <= '9' + 1 - n + field)
	{
		field = n - 1;
		while (arr[n - 1] <= '9')
		{
			print_one(n, 0, arr);
			arr[n - 1]++;
		}
	}
	else
	{
		field--;
		arr[field]++;
	}
	ft_print_combn2(n, field, arr);
}

void	ft_print_combn(int n)
{
	char	arr[10];
	 int	field;

	arr[0] = '0';
	field = 0;
	if (n == 1)
	{
		while (field <= 9)
		{
			print_one(n, 0, arr);
			arr[0]++;
			field++;
		}
	}
	if (n >= 2 && n < 10)
		ft_print_combn2(n, field, arr);
}

void	print_one(int n, int i, char *arr)
{
	if (i == n)
	{	
		if (arr[n - 1] == '9' && '9' - arr[0] == n - 1)
			return ;
		else
			write(1, ", ", 2);
	}
	else
	{
		write(1, &arr[i], 1);
		i++;
		print_one(n, i, arr);
	}
}
