/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:04:47 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/27 16:08:10 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *g, char *map)
{
	int	width;
	int	height;

	g->mlx = mlx_init();
	ft_null_check((int)g->mlx, "mlx_init failed\n", g);
	g->img = img_init(g->mlx, g);
	map_read(map, g);
	map_split(g);
	map_check(g);
	width = g->wid_len;
	height = g->hei_len;
	g->win = mlx_new_window(g->mlx, width * 64, height * 64, "so_long");
	ft_null_check((int)g->win, "mlx_new_window failed\n", g);
	img_set(g);
}

int	clear_game(t_game *g)
{
	g->count_mov++;
	ft_printf("%s %d%s\n", "Mission complete in ", g->count_mov, "steps");
	ft_t_game_free(g);
	exit(0);
}

int	exit_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	ft_t_game_free(g);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_error("Usage: ./so_long [MAP_FILE.ber]\n");
	if (map_extens_check(argv[1]) != 0)
		exit_error("Map file extension must be [.ber].\n");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit_error("Memory allocation failure");
	game_init(game, argv[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
