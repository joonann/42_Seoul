/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 05:57:32 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/26 05:57:35 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int key_code, t_game *g)
{
	if (key_code == KEY_ESC)
		exit_game(g);
	else if (key_code == KEY_W)
		move_up(g);
	else if (key_code == KEY_A)
		move_left(g);
	else if (key_code == KEY_S)
		move_down(g);
	else if (key_code == KEY_D)
		move_right(g);
	return (0);
}

void	move_up(t_game *g)
{
	int	i;
	int	j;

	i = find_p_i(g);
	j = find_p_j(g);
	if (g->map_tab[i - 1][j] == 'C')
		g->count_c++;
	if (g->map_tab[i - 1][j] == 'E' && g->all_c == g->count_c)
		clear_game(g);
	else if (g->map_tab[i - 1][j] != '1' && g->map_tab[i - 1][j] != 'E')
	{
		g->map_tab[i][j] = '0';
		g->map_tab[i - 1][j] = 'P';
		g->count_mov++;
		ft_printf("%d\n", g->count_mov);
		img_set(g);
	}
}

void	move_down(t_game *g)
{
	int	i;
	int	j;

	i = find_p_i(g);
	j = find_p_j(g);
	if (g->map_tab[i + 1][j] == 'C')
		g->count_c++;
	if (g->map_tab[i + 1][j] == 'E' && g->all_c == g->count_c)
		clear_game(g);
	else if (g->map_tab[i + 1][j] != '1' && g->map_tab[i + 1][j] != 'E')
	{
		g->map_tab[i][j] = '0';
		g->map_tab[i + 1][j] = 'P';
		g->count_mov++;
		ft_printf("%d\n", g->count_mov);
		img_set(g);
	}
}

void	move_left(t_game *g)
{
	int	i;
	int	j;

	i = find_p_i(g);
	j = find_p_j(g);
	if (g->map_tab[i][j - 1] == 'C')
		g->count_c++;
	if (g->map_tab[i][j - 1] == 'E' && g->all_c == g->count_c)
		clear_game(g);
	else if (g->map_tab[i][j - 1] != '1' && g->map_tab[i][j - 1] != 'E')
	{
		g->map_tab[i][j] = '0';
		g->map_tab[i][j - 1] = 'P';
		g->count_mov++;
		ft_printf("%d\n", g->count_mov);
		img_set(g);
	}
}

void	move_right(t_game *g)
{
	int	i;
	int	j;

	i = find_p_i(g);
	j = find_p_j(g);
	if (g->map_tab[i][j + 1] == 'C')
		g->count_c++;
	if (g->map_tab[i][j + 1] == 'E' && g->all_c == g->count_c)
		clear_game(g);
	else if (g->map_tab[i][j + 1] != '1' && g->map_tab[i][j + 1] != 'E')
	{
		g->map_tab[i][j] = '0';
		g->map_tab[i][j + 1] = 'P';
		g->count_mov++;
		ft_printf("%d\n", g->count_mov);
		img_set(g);
	}
}
