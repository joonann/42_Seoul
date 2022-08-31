/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:36:41 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/16 11:33:48 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_it(char n1, char n2, char n3, char n4)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, " ", 1);
	write(1, &n3, 1);
	write(1, &n4, 1);
}

void	ft_print_it(char n1, char n2, char n3, char n4)
{
	if (n1 == '9' && n2 == '8' && n3 == '9' && n4 == '9')
		print_it(n1, n2, n3, n4);
	else
	{
		print_it(n1, n2, n3, n4);
		write(1, ", ", 2);
	}	
}

void	right_comb(char left_n1, char left_n2)
{
	char	right_n1;
	char	right_n2;

	if (left_n2 == '9')
	{
		right_n1 = left_n1 + 1;
		right_n2 = '0';
	}
	else
	{
		right_n1 = left_n1;
		right_n2 = left_n2 + 1;
	}
	while (right_n1 <= '9')
	{
		while (right_n2 <= '9')
		{
			ft_print_it(left_n1, left_n2, right_n1, right_n2);
			right_n2++;
		}
		right_n1++;
		right_n2 = '0';
	}
}

void	ft_print_comb2(void)
{
	char	left_n1;
	char	left_n2;

	left_n1 = '0';
	left_n2 = '0';
	while (left_n1 <= '9')
	{
		while (left_n2 <= '9')
		{
			right_comb(left_n1, left_n2);
			left_n2++;
		}
		left_n1++;
		left_n2 = '0';
	}
}
