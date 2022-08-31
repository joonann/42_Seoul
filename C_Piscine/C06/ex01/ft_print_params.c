/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:32:57 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 15:37:22 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		index;
	int		loop;
	char	ch;

	index = 1;
	loop = 0;
	while (index < argc)
	{
		while (argv[index][loop])
		{
			ch = argv[index][loop];
			write(1, &ch, 1);
			loop++;
		}
		write(1, "\n", 1);
		loop = 0;
		index++;
	}
	return (0);
}
