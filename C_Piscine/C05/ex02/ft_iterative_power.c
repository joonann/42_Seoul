/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:46:21 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 20:01:54 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int	power)
{
	int	loop;
	int	result;

	loop = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	while (loop < power)
	{
		result *= nb;
		loop++;
	}
	return (result);
}
