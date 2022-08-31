/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:36:17 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/16 17:58:08 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_it(char *str)
{
	if (str[0] == '7' && str[1] == '8' && str[2] == '9')
	{	
		write(1, &str[0], 1);
		write(1, &str[1], 1);
		write(1, &str[2], 1);
	}
	else
	{
		write(1, &str[0], 1);
		write(1, &str[1], 1);
		write(1, &str[2], 1);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	num_comb[3];

	num_comb[0] = '0';
	num_comb[1] = '1';
	num_comb[2] = '2';
	while (num_comb[0] < '8')
	{
		while (num_comb[1] < '9')
		{
			while (num_comb[2] <= '9')
			{
				print_it(num_comb);
				num_comb[2]++;
			}
			num_comb[1]++;
			num_comb[2] = num_comb[1] + 1;
		}
		num_comb[0]++;
		num_comb[1] = num_comb[0] + 1;
		num_comb[2] = num_comb[1] + 1;
	}
}
