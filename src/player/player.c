/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:34:47 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/26 08:02:02 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//final point: = player position + vector direction * length
void	draw_player_ray(t_game *game)
{
	t_line	line;
	t_ray	ray;
	double	hit_x;
	double	hit_y;

	init_ray(&game->player, &ray, WIN_WIDTH / 2);
	cross_tile(game, &ray);
	wall_dist(&ray, &game->player);
	hit_x = game->player.x + ray.dirx * ray.wall_dist;//calculates impact point
	hit_y = game->player.y + ray.diry * ray.wall_dist;
	line.x0 = game->minimap.offset_x//starting point
		+ (int)(game->player.x * game->minimap.tile_size);
	line.y0 = game->minimap.offset_y
		+ (int)(game->player.y * game->minimap.tile_size);
	line.x1 = game->minimap.offset_x//final point
		+ (int)(hit_x * game->minimap.tile_size);
	line.y1 = game->minimap.offset_y
		+ (int)(hit_y * game->minimap.tile_size);
	draw_line(&game->display, line, COLOR_RAY);
}

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

void	draw_player_minimap(t_game *game)
{
	int	px;//player position -> center of circle
	int	py;
	int	r;

	r = 3;//fixed size for player in minimap
	px = game->minimap.offset_x + 
		(int)(game->player.x * game->minimap.tile_size);
	py = game->minimap.offset_y
		+ (int)(game->player.y * game->minimap.tile_size);
	draw_circle(&game->display, px, py, r);
}
