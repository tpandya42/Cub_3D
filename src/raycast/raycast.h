/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:40:24 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/24 19:29:28 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "debug.h"

void	raycast(t_game *game, int col);
void	step_side(t_ray *ray, t_player *player);
void	delta_dist(t_ray *ray);
void	ray_direction(t_ray *ray, t_player *player, int col, int WIN_WIDTH);

#endif