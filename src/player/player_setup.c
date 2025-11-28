/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:40:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/20 08:37:58 by albetanc         ###   ########.fr       */
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
	else//if it's not valid initial direction -> print a message? check parsing This is a default behav
		set_n_vect(player);//default
}


