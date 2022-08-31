/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:26:51 by yolee             #+#    #+#             */
/*   Updated: 2021/09/19 21:31:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

int		**ft_mat_memset(int size);
void	ft_mat_free(int size, int **mat);
void	ft_mat_init(int size, int **mat);
void	ft_print_map(int **map, int size);

void	ft_set_pos(int *copy_height_pos, int *height_pos, int size, int loop);
int		ft_is_dup(int size, int **map, int *height_pos);

void	ft_input_arr_set(int size, int **input_arr, char **argv);
int		ft_find_exception(int args, char **argv);
void	ft_find_sol(int *input_arr[], int size);
int		ft_find_rec_sol(int **input_arr, int size, int **map, int *height_pos);
int		ft_is_promising(int **input_arr, int size, int **map, int *height_pos);

int	ft_find_exception(int args, char **argv)
{
	int	loop;
	int	length;

	if ((args - 1) % 4 != 0)
	{
		return (0);
	}
	loop = 1;
	while (loop < args)
	{
		length = 0;
		while (argv[loop][length] != '\0')
		{
			if (!(argv[loop][length] > '0' && argv[loop][length] <= '9'))
				return (0);
			length++;
		}
		if (length != 1)
			return (0);
		loop++;
	}
	return (1);
}

void	ft_input_arr_set(int size, int **input_arr, char **argv)
{
	int	loop;

	input_arr[0] = malloc(sizeof(int) * size);
	input_arr[1] = malloc(sizeof(int) * size);
	input_arr[2] = malloc(sizeof(int) * size);
	input_arr[3] = malloc(sizeof(int) * size);
	loop = 0;
	while (loop < size)
	{
		input_arr[0][loop] = (int)(argv[1 + loop][0] - '0');
		input_arr[1][loop] = (int)(argv[1 + size * 1 + loop][0] - '0');
		input_arr[2][loop] = (int)(argv[1 + size * 2 + loop][0] - '0');
		input_arr[3][loop] = (int)(argv[1 + size * 3 + loop][0] - '0');
		loop++;
	}
}

void	ft_find_sol(int *input_arr[], int size)
{
	int	**map;
	int	loop;
	int	sol_found;
	int	height_pos[3];

	map = ft_mat_memset(size);
	ft_mat_init(size, map);
	height_pos[0] = size;
	height_pos[1] = 0;
	sol_found = 0;
	loop = 0;
	while (loop < size && !sol_found)
	{
		height_pos[2] = loop;
		sol_found = ft_find_rec_sol(input_arr, size, map, height_pos);
		loop++;
	}
	if (sol_found == 1)
		ft_print_map(map, size);
	else
		write(1, "error!\n", 7);
}

int	ft_find_rec_sol(int **input_arr, int size, int **map, int *height_pos)
{
	int	loop;
	int	sol_found;
	int	copy_height_pos[3];

	sol_found = 0;
	if (ft_is_dup(size, map, height_pos))
		map[height_pos[1]][height_pos[2]] = height_pos[0];
	else
		return (0);
	if (ft_is_promising(input_arr, size, map, height_pos))
	{
		loop = 0;
		while (loop < size && !(sol_found))
		{
			ft_set_pos(copy_height_pos, height_pos, size, loop);
			sol_found = ft_find_rec_sol(input_arr, size, map, copy_height_pos);
			loop++;
		}
	}
	if ((height_pos[0] == 1 && height_pos[1] == size - 1) || sol_found == 1)
		return (1);
	if (sol_found == 0)
		map[height_pos[1]][height_pos[2]] = 0;
	return (sol_found);
}

int	main(int args, char **argv)
{
	int	*input_arr[4];
	int	size;

	if (ft_find_exception(args, argv))
	{
		size = ((args - 1) / 4);
		ft_input_arr_set(size, input_arr, argv);
		ft_find_sol(input_arr, size);
	}
	else
		write(1, "error!\n", 7);
	return (0);
}
