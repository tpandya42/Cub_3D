/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:30:17 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 10:52:10 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_key(t_input_key *key)
{
	key->forward = 0;
	key->back = 0;
	key->left = 0;
	key->right = 0;
	key->rot_left = 0;
	key->rot_right = 0;
}

void	init_minimap(t_game *game)
{
	game->minimap.tile_size = MINIMAP_TILE;
	game->minimap.width = game->map.cols * MINIMAP_TILE;
	game->minimap.height = game->map.rows * MINIMAP_TILE;
	game->minimap.offset_x = MINIMAP_OFFSET_X;
	game->minimap.offset_y = MINIMAP_OFFSET_Y;
}

static int	ini_library(t_display *display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		print_error("Error: Unable to initialize mlx");
		return (1);
	}
	return (0);
}

int	init_display(t_display *display)
{
	if (ini_library(display))
		return (1);
	init_win(display);
	display->img = mlx_new_image(display->mlx, display->win_w, display->win_h);
	if (!display->img)
		return (1);
	display->addr = mlx_get_data_addr(display->img,
			&display->bpp,
			&display->line_len,
			&display->endian);
	if (!display->addr)
		return (1);
	return (0);
}
