/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:26:35 by yolee             #+#    #+#             */
/*   Updated: 2021/09/19 21:27:44 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include	<unistd.h>

int		**ft_mat_memset(int size);
void	ft_mat_free(int size, int **mat);
void	ft_mat_init(int size, int **mat);
void	ft_print_map(int **map, int size);

int	**ft_mat_memset(int size)
{
	int	**mat;
	int	loop;

	mat = malloc(sizeof(int *) * size);
	loop = 0;
	while (loop < size)
	{
		mat[loop] = malloc(sizeof(int) * size);
		loop++;
	}
	return (mat);
}

void	ft_mat_free(int size, int **mat)
{
	int	loop;

	loop = 0;
	while (loop < size)
	{
		free(mat[loop]);
		loop++;
	}
	free(mat);
}

void	ft_mat_init(int size, int **mat)
{
	int	loop1;
	int	loop2;

	loop1 = 0;
	while (loop1 < size)
	{
		loop2 = 0;
		while (loop2 < size)
		{
			mat[loop1][loop2] = 0;
			loop2++;
		}
		loop1++;
	}
}

void	ft_print_map(int **map, int size)
{
	int		loop1;
	int		loop2;
	char	print_chr;

	loop1 = 0;
	while (loop1 < size)
	{
		loop2 = 0;
		while (loop2 < size)
		{
			print_chr = map[loop1][loop2] + '0';
			write(1, &print_chr, 1);
			if (loop2 != size - 1)
				write(1, " ", 1);
			loop2++;
		}
		write(1, "\n", 1);
		loop1++;
	}
}
