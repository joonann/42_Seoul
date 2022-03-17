/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:41:49 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/30 11:18:36 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_put_positive_nbr(int p_nb)
{
	char	digit;

	if (p_nb <= 0)
		return ;
	ft_put_positive_nbr(p_nb / 10);
	digit = p_nb % 10 + '0';
	write(1, &digit, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write (1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb * (-1);
	}
	ft_put_positive_nbr(nb);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str)
	{
		ft_putstr(par[index].str);
		write(1, "\n", 1);
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		ft_putstr(par[index].copy);
		write(1, "\n", 1);
		index++;
	}
}
