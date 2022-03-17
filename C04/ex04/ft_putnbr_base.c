/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:21:28 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/28 10:21:50 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	base_exception(char *str)
{
	int	loop1;
	int	loop2;

	loop1 = 0;
	loop2 = 1;
	while (str[loop1])
	{
		if (str[loop1] == '+' || str[loop1] == '-')
			return (0);
		while (str[loop2])
		{
			if (str[loop1] == str[loop2])
				return (0);
			loop2++;
		}
		loop1++;
		loop2 = loop1 + 1;
	}
	return (1);
}

char	*ft_print_nbr_base(long long nbr, char *base, int base_len)
{
	if (nbr == 0)
		return (0);
	ft_print_nbr_base(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	number;

	number = nbr;
	if (base_len(base) < 2 || !base_exception(base))
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_print_nbr_base(number * (-1), base, base_len(base));
	}
	else
		ft_print_nbr_base(number, base, base_len(base));
}
