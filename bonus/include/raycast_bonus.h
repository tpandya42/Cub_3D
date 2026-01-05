/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:27:36 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:27:37 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

t_ray	raycast(t_game *game, int col);
void	init_ray(t_player *player, t_ray *ray, int col);
void	cross_tile(t_game *game, t_ray *ray);
void	wall_dist(t_ray *ray, t_player *player);
void	step_side(t_ray *ray, t_player *player);
void	delta_dist(t_ray *ray);
void	ray_direction(t_ray *ray, t_player *player, int col, int win_wid);

#endif
