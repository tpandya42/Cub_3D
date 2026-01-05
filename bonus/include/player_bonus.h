/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:27:19 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:27:21 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "cub.h"

void	draw_player_minimap(t_game *game);
void	setup_ini_vect(t_player *player, char initial_dir);
void	draw_player_ray(t_game *game);

#endif
