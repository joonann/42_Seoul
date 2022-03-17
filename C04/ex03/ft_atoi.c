/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:14:31 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/25 21:00:30 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	pos_neg;
	int	result;

	pos_neg = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pos_neg = pos_neg * (-1);
		str++;
	}
	if (str[0] < '0' || str[0] > '9')
		return (0);
	result = *str - 48;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (10 * result) + (*str - 48);
		str++;
	}
	return (pos_neg * result);
}
