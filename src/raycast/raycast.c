/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:02:31 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/25 18:16:34 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
* Finds perpendicular distance to the wall
*/
void	wall_dist(t_ray *ray, t_player *player)//CHEK THIS
{
	if (ray->side == 0) // vertical wall
		ray->wall_dist = (ray->current_x 
				- player->x + (1 - ray->step_x) / 2) / ray->dirx;
	else // horizontal wall
		ray->wall_dist = (ray->current_y 
				- player->y + (1 - ray->step_y) / 2) / ray->diry;
}

/*
* To step the ray through the map until it hits a wall
*/
void	cross_tile(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
	// Jump to next map tile in X or Y direction
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;  // move to next x-side
			ray->current_x += ray->step_x; // move mapX
			ray->side = 0; // hit was on a vertical side
		}
		else
		{
			ray->side_y += ray->delta_y;  // move to next y-side
			ray->current_y += ray->step_y; // move mapY
			ray->side = 1; // hit was on a horizontal side
		}
		// Check if ray has hit a wall
		if (game->map.map[ray->current_y][ray->current_x] == '1')
			hit = 1;
	}
}

/*
* Step direction and initial side distances
*/
void	init_ray(t_player *player, t_ray *ray, int col)
{
	ray->current_x = (int)player->x;
	ray->current_y = (int)player->y;
	ray->side = 0; //verical wall 9 and horizontal 1
	ray->wall_dist= 0.0;//will be calculated with dda
	ray_direction(ray, player, col, WIN_WIDTH);
	delta_dist(ray);
	step_side(ray, player);

}

void	raycast(t_game *game, int col)
{
	t_ray	ray;

	init_ray(&game->player, &ray, col);
	cross_tile(game, &ray);
	wall_dist(&ray, &game->player);//perpendicular
}
