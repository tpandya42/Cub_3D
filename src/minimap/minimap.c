/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:37 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 10:01:27 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// bpp = bytes por pixel
void	my_mlx_pixel_put(t_display *display, int x, int y, int color)
{
	char	*dst;
	int		bpp_bytes;

	if (x < 0 || x >= display->win_w || y < 0 || y >= display->win_h)
		return ;
	bpp_bytes = display->bpp / 8;
	dst = display->addr + (y * display->line_len + x * bpp_bytes);
	*(unsigned int *)dst = color;
}

static void	draw_square(t_game *game, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < game->minimap.tile_size)
	{
		dx = 0;
		while (dx < game->minimap.tile_size)
		{
			my_mlx_pixel_put(&game->display, x + dx, y + dy, color);
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
			if (game->map.grid[row][col] == '1') 
				color = COLOR_WALL;
			else
				color = COLOR_FLOOR;
			draw_square(game,
				game->minimap.offset_x + col * game->minimap.tile_size,
				game->minimap.offset_y + row * game->minimap.tile_size,
				color);
			col++;
		}
		row++;
	}
}

void	render_minimap(t_game *game)
{
	draw_minimap(game);
	draw_player_minimap(game);
	draw_player_ray(game);
}
