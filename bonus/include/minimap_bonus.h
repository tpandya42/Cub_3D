/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:26:43 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:26:45 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

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
