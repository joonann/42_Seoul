/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:26:25 by yolee             #+#    #+#             */
/*   Updated: 2021/09/19 21:30:39 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_set_pos(int *copy_height_pos, int *height_pos, int size, int loop);
int		ft_is_dup(int size, int **map, int *height_pos);

int	ft_is_dup(int size, int **map, int *height_pos)
{
	int	loop;

	if (map[height_pos[1]][height_pos[2]] != 0)
	{
		return (0);
	}
	loop = 0;
	while (loop < size)
	{
		if (map[height_pos[1]][loop] == height_pos[0]
			|| map[loop][height_pos[2]] == height_pos[0])
		{
			return (0);
		}
		loop++;
	}
	return (1);
}

void	ft_set_pos(int *copy_height_pos, int *height_pos, int size, int loop)
{
	if (height_pos[1] + 1 < size)
	{
		copy_height_pos[0] = height_pos[0];
		copy_height_pos[1] = height_pos[1] + 1;
	}
	else if (height_pos[0] - 1 > 0)
	{
		copy_height_pos[0] = height_pos[0] - 1;
		copy_height_pos[1] = 0;
	}
	else
	{
		copy_height_pos[0] = height_pos[0];
		copy_height_pos[1] = height_pos[1];
	}
	copy_height_pos[2] = loop;
}
