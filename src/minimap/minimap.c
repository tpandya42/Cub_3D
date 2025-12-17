/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:37 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/17 16:54:43 by albetanc         ###   ########.fr       */
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

static int	get_tile_color(char tile_char)
{
	if (tile_char == '1')
		return (COLOR_WALL);
	else if (tile_char == ' ')
		return (0x202020);
	else
		return (COLOR_FLOOR);
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
		while (col < game->map.cols && game->map.grid[row][col] != '\0')
		{
			color = get_tile_color(game->map.grid[row][col]);
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
	int	minimap_width;
	int	minimap_height;

	minimap_width = game->map.cols * game->minimap.tile_size;
	minimap_height = game->map.rows * game->minimap.tile_size;
	if ((game->minimap.offset_x + minimap_width) > game->display.win_w
		|| (game->minimap.offset_y + minimap_height) > game->display.win_h)
		return ;
	if (game->map.cols > MAX_MAP_COLS_DRAW
		|| game->map.rows > MAX_MAP_ROWS_DRAW)
		return ;
	draw_minimap(game);
	draw_player_minimap(game);
	draw_player_ray(game);
}
