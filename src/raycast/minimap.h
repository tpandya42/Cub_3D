/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:48:33 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/20 08:28:11 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIMAP_H
# define MINIMAP_H

#include "cub.h"

#define MINIMAP_TILE 16
#define MINIMAP_OFFSET_X 0
#define MINIMAP_OFFSET_Y 650
#define MINIMAP_TILE 16
#define MINIMAP_MARGIN 20 //from the window border
#define PLAYER_RADIUS 0.15//avoid colisions in cornres ->3d

void	my_mlx_pixel_put(t_display *display, int x, int y, int color);
void	draw_minimap(t_game *game);
void	draw_square(t_game *game, t_square square, int color);
void	draw_player_minimap(t_game *game);

#endif