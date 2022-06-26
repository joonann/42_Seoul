/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 05:57:25 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/26 08:20:22 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	tmp;
	int		wid;
	int		hei;

	tmp.tom = mlx_xpm_file_to_image(mlx, "./images/tom.xpm", &wid, &hei);
	tmp.jer = mlx_xpm_file_to_image(mlx, "./images/jer.xpm", &wid, &hei);
	tmp.tre = mlx_xpm_file_to_image(mlx, "./images/tre.xpm", &wid, &hei);
	tmp.bkg = mlx_xpm_file_to_image(mlx, "./images/bkg.xpm", &wid, &hei);
	tmp.bef = mlx_xpm_file_to_image(mlx, "./images/bef.xpm", &wid, &hei);
	tmp.aft = mlx_xpm_file_to_image(mlx, "./images/aft.xpm", &wid, &hei);
	return (tmp);
}

void	put_img(t_game *g, int h, int w)
{
	if (g->map_tab[h][w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.tre, w * 64, h * 64);
	else if (g->map_tab[h][w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.bef, w * 64, h * 64);
	else if (g->map_tab[h][w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img.tom, w * 64, h * 64);
	else if (g->map_tab[h][w] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.jer, w * 64, h * 64);
	else if (g->map_tab[h][w] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.bkg, w * 64, h * 64);
	else
		exit_error_free("Invalid map\n", g);
}

void	img_set(t_game *g)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei <= g->hei)
	{
		wid = 0;
		while (wid <= g->wid)
		{
			put_img(g, hei, wid);
			wid++;
		}
		hei++;
	}
}
