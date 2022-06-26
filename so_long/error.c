/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhkim <junhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:10:23 by junhkim           #+#    #+#             */
/*   Updated: 2022/06/26 10:10:34 by junhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	ft_t_game_free(t_game *g)
{
	int	i;

	if (g->map_str)
		free(g->map_str);
	if (g->map_tab)
	{
		i = 0;
		while (g->map_tab[i])
		{
			free(g->map_tab[i]);
			i++;
		}
		free(g->map_tab);
	}
}

void	exit_error_free(char *message, t_game *g)
{
	ft_t_game_free(g);
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

int	map_extens_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	return (ft_strncmp(filename + len - 4, ".ber", 4));
}
