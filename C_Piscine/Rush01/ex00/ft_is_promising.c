/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_promising.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:23:59 by yolee             #+#    #+#             */
/*   Updated: 2021/09/19 21:01:39 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_promising(int **input_arr, int size, int **map, int *height_pos);
int		ft_x_comp(int **input_arr, int size, int **map, int *height_pos);
int		ft_x_comp_r(int **input_arr, int size, int **map, int *height_pos);
int		ft_y_comp(int **input_arr, int size, int **map, int *height_pos);
int		ft_y_comp_r(int **input_arr, int size, int **map, int *height_pos);

int	ft_x_comp(int **input_arr, int size, int **map, int *height_pos)
{
	int	loop;
	int	max;
	int	max_count;
	int	min_count;

	max = -1;
	max_count = 0;
	min_count = 0;
	loop = 0;
	while (loop < size)
	{
		if (max <= map[height_pos[1]][loop])
		{
			max_count++;
			if (max != map[height_pos[1]][loop])
				min_count++;
			max = map[height_pos[1]][loop];
		}
		loop++;
	}
	if (max_count < input_arr[2][height_pos[1]]
		|| min_count > input_arr[2][height_pos[1]])
		return (1);
	return (0);
}

int	ft_x_comp_r(int **input_arr, int size, int **map, int *height_pos)
{
	int	loop;
	int	max;
	int	max_count;
	int	min_count;

	max = -1;
	max_count = 0;
	min_count = 0;
	loop = size - 1;
	while (loop >= 0)
	{
		if (max <= map[height_pos[1]][loop])
		{
			max_count++;
			if (max != map[height_pos[1]][loop])
				min_count++;
			max = map[height_pos[1]][loop];
		}
		loop--;
	}
	if (max_count < input_arr[3][height_pos[1]]
		|| min_count > input_arr[3][height_pos[1]])
		return (1);
	return (0);
}

int	ft_y_comp(int **input_arr, int size, int **map, int *height_pos)
{
	int	loop;
	int	max;
	int	max_count;
	int	min_count;

	max = -1;
	max_count = 0;
	min_count = 0;
	loop = 0;
	while (loop < size)
	{
		if (max <= map[loop][height_pos[2]])
		{
			max_count++;
			if (max != map[loop][height_pos[2]])
				min_count++;
			max = map[loop][height_pos[2]];
		}
		loop++;
	}
	if (max_count < input_arr[0][height_pos[2]]
		|| min_count > input_arr[0][height_pos[2]])
		return (1);
	return (0);
}

int	ft_y_comp_r(int **input_arr, int size, int **map, int *height_pos)
{
	int	loop;
	int	max;
	int	max_count;
	int	min_count;

	max = -1;
	max_count = 0;
	min_count = 0;
	loop = size - 1;
	while (loop >= 0)
	{
		if (max <= map[loop][height_pos[2]])
		{
			max_count++;
			if (max != map[loop][height_pos[2]])
				min_count++;
			max = map[loop][height_pos[2]];
		}
		loop--;
	}
	if (max_count < input_arr[1][height_pos[2]]
		|| min_count > input_arr[1][height_pos[2]])
		return (1);
	return (0);
}

int	ft_is_promising(int **input_arr, int size, int **map, int *height_pos)
{
	if (ft_x_comp(input_arr, size, map, height_pos))
		return (0);
	if (ft_x_comp_r(input_arr, size, map, height_pos))
		return (0);
	if (ft_y_comp(input_arr, size, map, height_pos))
		return (0);
	if (ft_y_comp_r(input_arr, size, map, height_pos))
		return (0);
	return (1);
}
