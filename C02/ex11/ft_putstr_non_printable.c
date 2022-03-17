/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:46:03 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/23 13:56:26 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned char ascii_num)
{
	const static char	hex[] = "0123456789abcdef";

	write(1, &hex[ascii_num / 16], 1);
	write(1, &hex[ascii_num % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((' ' <= str[index]) && (str[index] <= '~'))
			write(1, &str[index], 1);
		else
		{
			write(1, "\\", 1);
			ft_print_hex((unsigned char)str[index]);
		}
		index++;
	}
}
