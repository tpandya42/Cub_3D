/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:06:17 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/19 09:06:37 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "cub.h"

//General
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define TILE_SIZE 64
# define M_SPEED 0.05
# define ROT_SPEED 0.05
# define COLLI_DIST 0.5

//Raycasting
# define CAMERA_PLANE_X 0.2
# define RAY_MINIMAP_LEN 3.0

//Minimap
# define PLAYER_SIZE 3
# define MAX_MAP_COLS_DRAW 25
# define MAX_MAP_ROWS_DRAW 25

#endif
