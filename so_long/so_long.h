/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:06 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/26 08:56:56 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "key.h"
# include "./mlx/mlx.h"
# include "./lib/libft/libft.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*tom;
	void	*jer;
	void	*tre;
	void	*bkg;
	void	*bef;
	void	*aft;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	int		wid_len;
	int		hei_len;
	char	*map_str;
	char	**map_tab;
	int		all_c;
	int		count_c;
	int		count_mov;
}	t_game;

t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	img_set(t_game *g);

int		press_key(int key_code, t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);

int		find_p_i(t_game *g);
int		find_p_j(t_game *g);

void	game_init(t_game *g, char *map);
int		clear_game(t_game *t);
int		exit_game(t_game *g);
void	exit_error(char *message);
int		main(int argc, char **argv);

void	map_read(char *filename, t_game *g);
void	map_split(t_game *g);
void	map_check_wall(t_game *g);
void	map_check_params(t_game *g);
void	map_check(t_game *g);
void	exit_error_free(char *message, t_game *g);
void	ft_t_game_free(t_game *g);
int		map_extens_check(char *filename);

#endif
