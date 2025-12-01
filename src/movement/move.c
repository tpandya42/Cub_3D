/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:49:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/01 10:57:14 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.dir_x * game->player.move_speed;
	ny = game->player.y + game->player.dir_y * game->player.move_speed;
	if (game->player.dir_x > 0)
	{
		if (game->map.map[(int)game->player.y][(int)nx] != '1')
			game->player.x = nx;
	}
	else
	{
		if (game->map.map[(int)game->player.y][(int)(nx - COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	if (game->player.dir_y > 0)
	{
		if (game->map.map[(int)ny][(int)game->player.x] != '1')
			game->player.y = ny;
	}
	else
	{
		if (game->map.map[(int)(ny - COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
}

void	move_back(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x - game->player.dir_x * game->player.move_speed;
	ny = game->player.y - game->player.dir_y * game->player.move_speed;
	//if (game->map.map[(int)game->player.y][(int)nx] != '1')
	//	game->player.x = nx;
	//if (game->map.map[(int)ny][(int)game->player.x] != '1')
	//	game->player.y = ny;
	if (game->player.dir_x > 0)
	{
		if (game->map.map[(int)game->player.y][(int)(nx + COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	else
	{
		if (game->map.map[(int)game->player.y][(int)(nx - COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	if (game->player.dir_y > 0)
	{
		if (game->map.map[(int)(ny + COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
	else
	{
		if (game->map.map[(int)(ny - COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
}

void	move_left(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x - game->player.plane_x * game->player.move_speed;
	ny = game->player.y - game->player.plane_y * game->player.move_speed;
	//if (game->map.map[(int)game->player.y][(int)nx] != '1')
	//	game->player.x = nx;
	//if (game->map.map[(int)ny][(int)game->player.x] != '1')
	//	game->player.y = ny;
	if (game->player.plane_x > 0)
	{
		if (game->map.map[(int)game->player.y][(int)(nx + COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	else
	{
		if (game->map.map[(int)game->player.y][(int)(nx - COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	if (game->player.plane_y > 0)
	{
		if (game->map.map[(int)(ny + COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
	else
	{
		if (game->map.map[(int)(ny - COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
}

void	move_right(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.plane_x * game->player.move_speed;
	ny = game->player.y + game->player.plane_y * game->player.move_speed;
	//if (game->map.map[(int)game->player.y][(int)nx] != '1')
	//	game->player.x = nx;
	//if (game->map.map[(int)ny][(int)game->player.x] != '1')
	//	game->player.y = ny;
	if (game->player.plane_x > 0)
	{
		if (game->map.map[(int)game->player.y][(int)(nx + COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	else
	{
		if (game->map.map[(int)game->player.y][(int)(nx - COLLI_DIST)] != '1')
			game->player.x = nx;
	}
	if (game->player.plane_y > 0)
	{
		if (game->map.map[(int)(ny + COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
	else
	{
		if (game->map.map[(int)(ny - COLLI_DIST)][(int)game->player.x] != '1')
			game->player.y = ny;
	}
}

void	handle_movement(t_game *game)
{
	if (game->key.forward)
		move_forward(game);
	if (game->key.back)
		move_back(game);
	if (game->key.left)
		move_left(game);
	if (game->key.right)
		move_right(game);
	if (game->key.rot_left)
		rotate_left(game);
	if (game->key.rot_right)
		rotate_right(game);
}
