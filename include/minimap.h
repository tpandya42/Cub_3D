/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:48:33 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 12:50:16 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub.h"

# define MINIMAP_TILE 16
# define MINIMAP_OFFSET_X 0
# define MINIMAP_OFFSET_Y 650
# define MINIMAP_TILE 16
# define MINIMAP_MARGIN 20

void	render_minimap(t_game *game);
void	my_mlx_pixel_put(t_display *display, int x, int y, int color);
void	draw_minimap(t_game *game);
void	draw_player_minimap(t_game *game);

#endif