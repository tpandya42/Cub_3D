/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:21:09 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 18:23:57 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub.h"

void	setup_initial_vectors(t_player *player, char ini_dir);
int		render_scene(t_game *game);
int		key_release(int keycode, void *param);
int		key_press(int keycode, void *param);

#endif