/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:30:17 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 18:19:11 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->bpp = 0;
	display->line_len = 0;
	display->endian = 0;
	return (0);
}
