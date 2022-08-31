/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:38:54 by junhkim           #+#    #+#             */
/*   Updated: 2021/09/26 15:43:21 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		index;
	int		loop;
	char	ch;

	index = argc - 1;
	loop = 0;
	while (index > 0)
	{
		while (argv[index][loop])
		{
			ch = argv[index][loop];
			write(1, &ch, 1);
			loop++;
		}
		loop = 0;
		index--;
		write(1, "\n", 1);
	}
	return (0);
}
