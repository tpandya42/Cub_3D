/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:30:00 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 13:39:37 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>

# define DEBUG 0

# if DEBUG == 1
#  define DEBUG_PRINT(fmt, ...) \
	fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)
#  define DEBUG_PLAYER(player) \
	fprintf(stderr, "[DEBUG] Player: pos=(%.3f, %.3f) dir=(%.3f, %.3f)\n", \
		(player).x, (player).y, (player).dir_x, (player).dir_y)
#  define DEBUG_RAY(ray) \
	fprintf(stderr, "[DEBUG] Ray: dist=%.3f side=%d step_x=%d step_y=%d\n", \
		(ray)->wall_dist, (ray)->side, (ray)->step_x, (ray)->step_y)
#  define DEBUG_WALL(wall_h, start, end) \
	fprintf(stderr, "[DEBUG] Wall: height=%d start=%d end=%d\n", \
		wall_h, start, end)
# else
#  define DEBUG_PRINT(fmt, ...)
#  define DEBUG_PLAYER(player)
#  define DEBUG_RAY(ray)
#  define DEBUG_WALL(wall_h, start, end)
# endif

#endif
