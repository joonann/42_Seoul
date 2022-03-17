/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suekang <suekang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:11:05 by suekang           #+#    #+#             */
/*   Updated: 2021/09/12 18:01:59 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rush(int flag, char a, char b)
{
	if (flag == 1 )
		ft_putchar(a);
	else
		ft_putchar(b);
}

void	rush(int x, int y)
{
	int	row;
	int	column;
	int	flag;

	row = 0;
	while (x >= 1 && row < y)
	{
		column = 0;
		while (column < x)
		{	
			flag = 0;
			if ((column == 0) || (column == x - 1))
				flag = 1;
			if (row == 0)
				print_rush (flag, 'A', 'B');
			else if (row == y - 1)
				print_rush (flag, 'C', 'B');
			else
				print_rush (flag, 'B', ' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
