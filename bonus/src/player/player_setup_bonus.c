/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:29 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:36:30 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_n_vect(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1.0;
	player->plane_x = CAMERA_PLANE_X;
	player->plane_y = 0;
}

void	set_s_vect(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1.0;
	player->plane_x = -CAMERA_PLANE_X;
	player->plane_y = 0;
}

void	set_e_vect(t_player *player)
{
	player->dir_x = 1.0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = CAMERA_PLANE_X;
}

void	set_w_vect(t_player *player)
{
	player->dir_x = -1.0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -CAMERA_PLANE_X;
}

void	setup_ini_vect(t_player *player, char initial_dir)
{
	if (initial_dir == 'N')
		set_n_vect(player);
	else if (initial_dir == 'S')
		set_s_vect(player);
	else if (initial_dir == 'E')
		set_e_vect(player);
	else if (initial_dir == 'W')
		set_w_vect(player);
	else
		set_n_vect(player);
}
