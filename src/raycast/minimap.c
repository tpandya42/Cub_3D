/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:37 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/20 08:30:03 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_display *display, int x, int y, int color)
{
	char	*dst;
	int		bpp_bytes; // bytes por pixel

	if (x < 0 || x >= display->win_w || y < 0 || y >= display->win_h)
		return ;
	bpp_bytes = display->bpp / 8;
	dst = display->addr + (y * display->line_len + x * bpp_bytes);
	*(unsigned int *)dst = color;
}

void	draw_square(t_game *game, t_square square, int color)
{
	int	current_x;
	int	current_y;

	current_y = 0;
	while (current_y < square.side_len)
	{
		current_x = 0;
		while (current_x < square.side_len)
		{
			my_mlx_pixel_put(&game->display, square.x_topleft 
				+ current_x, square.y_topleft + current_y, color);
			current_x++;
		}
		current_y++;
	}
}

void	draw_minimap(t_game *game)
{
	t_square	square;
	int			row;
	int			col;
	int			color;

	square.side_len = game->minimap.tile_size;
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
			square.x_topleft = game->minimap.offset_x + col * square.side_len;
			square.y_topleft = game->minimap.offset_y + row * square.side_len;
			draw_square(game, square, color);
			col++;
		}
		row++;
	}
}



