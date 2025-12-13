/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:34:47 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 11:16:39 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
* final point: = player position + vector direction * length
* hit_x calculates impact point
* offset_x from where to draw
* line.x0 starting point to draw minimap
* line.x1 final point to draw in minimap
*/
void	draw_player_ray(t_game *game)
{
	t_line	line;
	t_ray	ray;
	double	hit_x;
	double	hit_y;

	init_ray(&game->player, &ray, WIN_WIDTH / 2);
	cross_tile(game, &ray);
	wall_dist(&ray, &game->player);
	hit_x = game->player.x + ray.dirx * ray.wall_dist;
	hit_y = game->player.y + ray.diry * ray.wall_dist;
	line.x0 = game->minimap.offset_x
		+ (int)(game->player.x * game->minimap.tile_size);
	line.y0 = game->minimap.offset_y
		+ (int)(game->player.y * game->minimap.tile_size);
	line.x1 = game->minimap.offset_x
		+ (int)(hit_x * game->minimap.tile_size);
	line.y1 = game->minimap.offset_y
		+ (int)(hit_y * game->minimap.tile_size);
	draw_line(&game->display, line, COLOR_RAY);
}

/*
* draws a circle using an approximate Bresenham point algorithm 
* (x^2+y^2≤r^2)
* iterating pixels in a 2r-sided square centered at (cx,cy) 
* and painting those within the radius.
*/
void	draw_circle(t_display *disp, int cx, int cy, int r)
{
	int	x;
	int	y;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(disp, cx + x, cy + y, COLOR_PLAYER);
			x++;
		}
		y++;
	}
}

/*
* px is the player position, the center of the circle
* r is the size for player
*/
void	draw_player_minimap(t_game *game)
{
	int	px;
	int	py;
	int	r;

	r = PLAYER_SIZE;
	px = game->minimap.offset_x + 
		(int)(game->player.x * game->minimap.tile_size);
	py = game->minimap.offset_y
		+ (int)(game->player.y * game->minimap.tile_size);
	draw_circle(&game->display, px, py, r);
}
