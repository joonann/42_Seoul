/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:34:17 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/19 09:38:25 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(int p_nb)
{
	int	i;
	int	quo;

	i = 0;
	quo = p_nb;
	while (quo != 0)
	{
		quo = quo / 10;
		i++;
	}
	return (i);
}

int	ten_square(int n)
{
	int	a;

	a = 1;
	if (n == 0)
		return (a);
	else
	{
		while (n != 0)
		{
			a = a * 10;
			n--;
		}
	}
	return (a);
}

void	ft_putnbr_p(int p_nb)
{
	int		l;
	char	r;

	l = ft_len(p_nb);
	while (l != 0)
	{
		r = p_nb / ten_square(l - 1) + 48;
		p_nb = p_nb % ten_square(l - 1);
		write(1, &r, 1);
		l--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_p(nb * (-1));
	}
	else if (nb == 0)
		write(1, "0", 1);
	else
		ft_putnbr_p(nb);
}
