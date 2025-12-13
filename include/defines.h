/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:28:02 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 16:27:44 by albetanc         ###   ########.fr       */
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
# define ALL_IDS (ID_NO|ID_SO|ID_WE|ID_EA|ID_F|ID_C)

//Raycasting
# define CAMERA_PLANE_X 0.2
# define RAY_MINIMAP_LEN 3.0

//Minimap
# define PLAYER_SIZE 3
#define MAX_MAP_COLS_DRAW 25
#define MAX_MAP_ROWS_DRAW 25

#endif