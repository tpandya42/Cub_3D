/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:48:33 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 18:26:31 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define MINIMAP_TILE 16
#define MINIMAP_OFFSET_X 0
#define MINIMAP_OFFSET_Y 650
#define MINIMAP_TILE 16

void	draw_minimap(t_game *game);
void	draw_player_minimap(t_game *game);
