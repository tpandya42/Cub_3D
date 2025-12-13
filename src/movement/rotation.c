/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:09:49 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 10:13:27 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//rs negative
void	rotate_left(t_game *game)
{
	double	old_dir_x; 
	double	old_plane_x;
	double	rs;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	rs = game->player.rot_speed;
	game->player.dir_x = game->player.dir_x * cos(rs)
		- game->player.dir_y * sin(rs);
	game->player.dir_y = old_dir_x * sin(rs)
		+ game->player.dir_y * cos(rs);
	game->player.plane_x = game->player.plane_x * cos(rs)
		- game->player.plane_y * sin(rs);
	game->player.plane_y = old_plane_x * sin(rs)
		+ game->player.plane_y * cos(rs);
}

//old_plane_x = positive -> clockwise
void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rs;

	rs = game->player.rot_speed;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rs) 
		+ game->player.dir_y * sin(rs);
	game->player.dir_y = -old_dir_x * sin(rs) 
		+ game->player.dir_y * cos(rs);
	game->player.plane_x = game->player.plane_x * cos(rs) 
		+ game->player.plane_y * sin(rs);
	game->player.plane_y = -old_plane_x * sin(rs) 
		+ game->player.plane_y * cos(rs);
}
