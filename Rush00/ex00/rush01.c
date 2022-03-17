/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:00:02 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/12 17:43:00 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rush(int row, int col, int x, int y)
{
	if (row == 0 && col == 0)
		ft_putchar('/');
	else if (row == 0 && col == x - 1)
		ft_putchar('\\');
	else if (row == y - 1 && col == 0)
		ft_putchar('\\');
	else if (row == y - 1 && col == x - 1)
		ft_putchar('/');
	else if ((row == 0 || row == y - 1) && col > 0 && col < x - 1)
		ft_putchar('*');
	else if ((col == 0 || col == x - 1) && row > 0 && row < y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row_coord;
	int	col_coord;

	row_coord = 0;
	col_coord = 0;
	if (x < 1 || y < 1)
		return ;
	while (row_coord < y)
	{
		while (col_coord < x)
		{
			print_rush(row_coord, col_coord, x, y);
			col_coord++;
		}
		ft_putchar('\n');
		row_coord++;
		col_coord = 0;
	}
}
