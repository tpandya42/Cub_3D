/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:37 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 17:54:06 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MINIMAP_MARGIN 20 //from the window border
#include "cub.h"

void	draw_player_minimap(t_game *game)
{
	int	px;
	int	py;

	px = game->minimap.offset_x + 
		(int)(game->player.x * game->minimap.tile_size);
	py = game->minimap.offset_y
		+ (int)(game->player.y * game->minimap.tile_size);
	mlx_pixel_put(game->display.mlx, game->display.win,
		px, py, COLOR_PLAYER);
}

static void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	dx;//delta x
	int	dy;//delta y

	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			mlx_pixel_put(game->display.mlx, game->display.win,
				x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	int	row;
	int	col;
	int	color;

	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.cols)
		{
			if (game->map.map[row][col] == '1') 
				color = COLOR_WALL;
			else
				color = COLOR_FLOOR;
			draw_square(game,
				game->minimap.offset_x + col * game->minimap.tile_size,
				game->minimap.offset_y + row * game->minimap.tile_size,
				game->minimap.tile_size,
				color);
			col++;
		}
		row++;
	}
}



