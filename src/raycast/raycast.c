/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:02:31 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 10:21:59 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
* Finds perpendicular distance to the wall
* side == 0 is vertical wall (E/W)
* else it's horizontal wall(N/S)
*/
void	wall_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = ((double)ray->current_x
				- player->x + (1 - ray->step_x) / 2) / ray->dirx;
	else
		ray->wall_dist = (ray->current_y 
				- player->y + (1 - ray->step_y) / 2) / ray->diry;
	if (ray->wall_dist < 0.1)
		ray->wall_dist = 0.1;
}

/*
* To step the ray through the map until it hits a wall
* 1. Jump to next map tile in X or Y direction:
*		delta_x move to next x-side
*		step_x move mpaX
		side 0 is vertical side and 1 is hrz
* 2. Check if ray has hit a wall
*/
void	cross_tile(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->current_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->current_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.grid[ray->current_y][ray->current_x] == '1')
			hit = 1;
	}
}

/*
* Step direction and initial side distances
* side = 0 vertical wall
*/
void	init_ray(t_player *player, t_ray *ray, int col)
{
	ray->current_x = (int)player->x;
	ray->current_y = (int)player->y;
	ray->side = 0;
	ray->wall_dist = 0.0;
	ray_direction(ray, player, col, WIN_WIDTH);
	delta_dist(ray);
	step_side(ray, player);
}

t_ray	raycast(t_game *game, int col)
{
	t_ray	ray;

	init_ray(&game->player, &ray, col);
	cross_tile(game, &ray);
	wall_dist(&ray, &game->player);
	if (ray.side == 0)
		ray.hit = game->player.y + ray.wall_dist * ray.diry;
	else
		ray.hit = game->player.x + ray.wall_dist * ray.dirx;
	ray.hit -= floor(ray.hit);
	return (ray);
}
