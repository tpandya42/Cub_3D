/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:35:38 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 12:54:56 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub.h"

void	draw_player_minimap(t_game *game);
void	setup_ini_vect(t_player *player, char initial_dir);
void	draw_player_ray(t_game *game);

#endif