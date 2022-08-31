/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:51:06 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 18:31:44 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		loop;
	char	ch;

	loop = 0;
	if (argc > 0)
	{
		while (argv[0][loop])
		{
			ch = argv[0][loop];
			write(1, &ch, 1);
			loop++;
		}
	}
	write(1, "\n", 1);
	return (0);
}	
