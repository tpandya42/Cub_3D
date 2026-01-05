/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:27:43 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:27:44 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "cub.h"

void	setup_initial_vectors(t_player *player, char ini_dir);
int		render_scene(t_game *game);
int		key_release(int keycode, void *param);
int		key_press(int keycode, void *param);

//render_wall.c
void	render_wall(t_game *game, int col, t_ray *ray);

//render_utils.c
int		ceiling_color(t_game *game);
int		floor_color(t_game *game);
int		sample_texture(t_wall_data *tex, int x, int y);

#endif
