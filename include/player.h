/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:35:38 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/20 08:12:52 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub.h"

void	draw_player_minimap(t_game *game);
void	setup_ini_vect(t_player *player, char initial_dir);
//void	draw_player_ray(t_game *game);
void	draw_player_ray(t_game *game);

#endif