/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:27:40 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/04 08:49:42 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
* Compute the ray direction based on player
* direction and camera plane
* camera plane x-coordinate
*/
void	ray_direction(t_ray *ray, t_player *player, int col, int win_wid)
{
	double	camera_x;

	camera_x = 2.0 * col / (double)win_wid - 1.0;
	ray->dirx = player->dir_x + player->plane_x * camera_x;
	ray->diry = player->dir_y + player->plane_y * camera_x;
}

/*
* Calculate how far the ray must go to cross one x or y grid
* 1e30 to avoid division by 0
*/
void	delta_dist(t_ray *ray)
{
	if (ray->dirx == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1.0 / ray->dirx);
	if (ray->diry == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1.0 / ray->diry);
}

/*
* Step in X and initial side_x
*/
static void	calculate_x(t_ray *ray, t_player *player)
{
	if (ray->dirx < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->x - ray->current_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->current_x + 1.0 - player->x) * ray->delta_x;
	}
}


/*
* Step in y and initial side_y
*/
static void	calculate_y(t_ray *ray, t_player *player)
{
	if (ray->diry < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->y - ray->current_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->current_y + 1.0 - player->y) * ray->delta_y;
	}
}

/*
* Calculates the step direction and initial side distances
*/
void	step_side(t_ray *ray, t_player *player)
{
	calculate_x(ray, player);
	calculate_y(ray, player);
}
