/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:31:36 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 17:31:38 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	loop;

	loop = 2;
	if (nb < 2)
		return (0);
	while (loop < nb && loop <= 46340)
	{
		if (nb % loop == 0)
			return (0);
		loop++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	nbr;

	nbr = nb;
	while (1)
	{
		if (ft_is_prime(nbr))
			return (nbr);
		nbr++;
	}
}
