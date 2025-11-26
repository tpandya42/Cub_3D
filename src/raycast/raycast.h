/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:40:24 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/25 17:48:23 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "debug.h"

void	raycast(t_game *game, int col);
void	init_ray(t_player *player, t_ray *ray, int col);
void	cross_tile(t_game *game, t_ray *ray);
void	wall_dist(t_ray *ray, t_player *player);
void	step_side(t_ray *ray, t_player *player);
void	delta_dist(t_ray *ray);
void	ray_direction(t_ray *ray, t_player *player, int col, int win_wid);

#endif