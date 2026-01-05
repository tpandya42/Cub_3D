/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:34:15 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:34:17 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_wall(char c)
{
	return (c == '1');
}

void	move_left(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.dir_y * game->player.move_speed;
	ny = game->player.y - game->player.dir_x * game->player.move_speed;
	if (!is_wall(game->map.grid[(int)game->player.y][(int)(nx
			+ game->player.dir_y * COLLI_DIST)]))
		game->player.x = nx;
	if (!is_wall(game->map.grid[(int)(ny - game->player.dir_x
				* COLLI_DIST)][(int)game->player.x]))
		game->player.y = ny;
}

void	move_right(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x - game->player.dir_y * game->player.move_speed;
	ny = game->player.y + game->player.dir_x * game->player.move_speed;
	if (!is_wall(game->map.grid[(int)game->player.y][(int)(nx
			- game->player.dir_y * COLLI_DIST)]))
		game->player.x = nx;
	if (!is_wall(game->map.grid[(int)(ny + game->player.dir_x
				* COLLI_DIST)][(int)game->player.x]))
		game->player.y = ny;
}

// all movements include colision distance
void	move_forward(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x + game->player.dir_x * game->player.move_speed;
	ny = game->player.y + game->player.dir_y * game->player.move_speed;
	if (!is_wall(game->map.grid[(int)game->player.y][(int)(nx
			+ game->player.dir_x * COLLI_DIST)]))
		game->player.x = nx;
	if (!is_wall(game->map.grid[(int)(ny + game->player.dir_y
				* COLLI_DIST)][(int)game->player.x]))
		game->player.y = ny;
}

void	move_back(t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.x - game->player.dir_x * game->player.move_speed;
	ny = game->player.y - game->player.dir_y * game->player.move_speed;
	if (!is_wall(game->map.grid[(int)game->player.y][(int)(nx
			- game->player.dir_x * COLLI_DIST)]))
		game->player.x = nx;
	if (!is_wall(game->map.grid[(int)(ny - game->player.dir_y
				* COLLI_DIST)][(int)game->player.x]))
		game->player.y = ny;
}
