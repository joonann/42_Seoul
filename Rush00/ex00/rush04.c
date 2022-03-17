/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwki <youngwki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:59:34 by youngwki          #+#    #+#             */
/*   Updated: 2021/09/12 18:17:06 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putchar(char c);

void	column_check1(int a, int x)
{
	if (a == 1)
		ft_putchar('A');
	else if (a == x)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	column_check2(int a, int x)
{
	if (a == 1)
		ft_putchar('B');
	else if (a == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	column_check3(int a, int x)
{
	if (a == 1)
		ft_putchar('C');
	else if (a == x)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	p;
	int	q;

	if (x >= 1 && y >= 1)
	{
		q = 1;
		while (q <= y)
		{
			p = 1;
			while (p <= x)
			{
				if (q == 1)
					column_check1(p, x);
				else if (q == y)
					column_check3(p, x);
				else
					column_check2(p, x);
				p = p + 1;
			}
			ft_putchar('\n');
			q = q + 1;
		}
	}
}
