/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:49:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 15:11:13 by albetanc         ###   ########.fr       */
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

//all movements include colision distance
void	move_forward(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.dir_x * game->player.move_speed;
	ny = game->player.y + game->player.dir_y * game->player.move_speed;
	if (game->map.grid[(int)game->player.y]
		[(int)(nx + game->player.dir_x * COLLI_DIST)] != '1')
		game->player.x = nx;
	if (game->map.grid[(int)(ny + game->player.dir_y * COLLI_DIST)]
		[(int)game->player.x] != '1')
		game->player.y = ny;
}

void	move_back(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x - game->player.dir_x * game->player.move_speed;
	ny = game->player.y - game->player.dir_y * game->player.move_speed;
	if (game->map.grid[(int)game->player.y]
		[(int)(nx - game->player.dir_x * COLLI_DIST)] != '1')
		game->player.x = nx;
	if (game->map.grid[(int)(ny - game->player.dir_y * COLLI_DIST)]
		[(int)game->player.x] != '1')
		game->player.y = ny;
}

void	handle_movement(t_game *game)
{
	if (game->key.forward)
		move_forward(game);
	if (game->key.back)
		move_back(game);
	if (game->key.rot_left || game->key.left)
		rotate_left(game);
	if (game->key.rot_right || game->key.right)
		rotate_right(game);
}
