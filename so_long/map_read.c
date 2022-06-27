/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:33:21 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/27 15:33:10 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *filename, t_game *g)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Map file open failed\n");
	line = get_next_line(fd);
	ft_null_check((int)line, "map_read failed", g);
	g->hei = 0;
	g->wid = ft_strlen(line) - 2;
	g->map_str = ft_strdup(line);
	ft_null_check((int)g->map_str, "map_read failed\n", g);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			g->hei++;
			g->map_str = ft_strjoin(g->map_str, line);
			ft_null_check((int)g->map_str, "map_read failed\n", g);
		}
	}
	close(fd);
}

void	map_split(t_game *g)
{
	g->map_tab = ft_split(g->map_str, '\n');
	ft_null_check((int)g->map_tab, "map_split failed\n", g);
	g->wid_len = g->wid + 1;
	g->hei_len = g->hei + 1;
	g->count_mov = 0;
}

void	map_check_wall(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map_tab[i])
	{
		j = 0;
		while (g->map_tab[i][j])
		{
			if (i == 0 || j == 0 || i == g->hei || j == g->wid)
			{
				if (g->map_tab[i][j] != '1')
					exit_error_free("Map isn't surrounded by walls\n", g);
			}
			j++;
		}
		i++;
	}
}

void	map_check_params(t_game *g)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	g->all_c = 0;
	g->count_c = 0;
	while (i++ < (int)ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'E')
			num_e++;
		else if (g->map_str[i] == 'P')
			num_p++;
		else if (g->map_str[i] == 'C')
			g->all_c++;
	}
	if (num_e == 0)
		exit_error_free("Map must have at least one exit\n", g);
	if (g->all_c == 0)
		exit_error_free("Map must have at least one collectible\n", g);
	if (num_p != 1)
		exit_error_free("Map must have only one starting position\n", g);
}

void	map_check(t_game *g)
{
	int	i;

	i = 0;
	while (g->map_tab[i])
	{
		if ((int)ft_strlen(g->map_tab[i]) != g->wid + 1)
		{
			exit_error_free("Map must be rectangular\n", g);
		}
		i++;
	}
	map_check_wall(g);
	map_check_params(g);
}
