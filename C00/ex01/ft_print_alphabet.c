/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:54:15 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/16 11:30:57 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alph_code;

	alph_code = 'a';
	while (alph_code <= 'z')
	{
		write(1, &alph_code, 1);
		alph_code++;
	}
}
