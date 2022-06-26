/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_find_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:04:40 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/26 07:04:41 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_p_i(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map_tab[i])
	{
		j = 0;
		while (g->map_tab[i][j])
		{
			if (g->map_tab[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_p_j(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map_tab[i])
	{
		j = 0;
		while (g->map_tab[i][j])
		{
			if (g->map_tab[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}
