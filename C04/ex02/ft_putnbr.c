/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:25:39 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/25 19:57:06 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb * (-1);
	}
	ft_put_positive_nbr(nb);
}
