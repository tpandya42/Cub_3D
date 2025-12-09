/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:02:31 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/03 19:25:38 by albetanc         ###   ########.fr       */
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
* Check if position is a wall (includes bounds check)
*/
static int	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return (1);
	if (game->map.grid[y][x] == '1' || game->map.grid[y][x] == ' ')
		return (1);
	return (0);
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
		if (ray->side_x <= ray->side_y)
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
		if (is_wall(game, ray->current_x, ray->current_y))
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

t_ray	raycast(t_game *game, int col)
{
	t_ray	ray;

	init_ray(&game->player, &ray, col);
	cross_tile(game, &ray);
	wall_dist(&ray, &game->player);
	return (ray);
}
