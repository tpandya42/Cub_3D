/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:49:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/02 08:57:28 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_blocked(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return (1);
	if (game->map.grid[y][x] == '1' || game->map.grid[y][x] == ' ')
		return (1);
	return (0);
}

void	move_forward(t_game *game)
{
	double	nx;
	double	ny;
	int		check_x;
	int		check_y;

	nx = game->player.x + game->player.dir_x * game->player.move_speed;
	ny = game->player.y + game->player.dir_y * game->player.move_speed;
	check_x = (int)(nx + game->player.dir_x * COLLI_DIST);
	check_y = (int)(ny + game->player.dir_y * COLLI_DIST);
	if (!is_blocked(game, check_x, (int)game->player.y))
		game->player.x = nx;
	if (!is_blocked(game, (int)game->player.x, check_y))
		game->player.y = ny;
}

void	move_back(t_game *game)
{
	double	nx;
	double	ny;
	int		check_x;
	int		check_y;

	nx = game->player.x - game->player.dir_x * game->player.move_speed;
	ny = game->player.y - game->player.dir_y * game->player.move_speed;
	check_x = (int)(nx - game->player.dir_x * COLLI_DIST);
	check_y = (int)(ny - game->player.dir_y * COLLI_DIST);
	if (!is_blocked(game, check_x, (int)game->player.y))
		game->player.x = nx;
	if (!is_blocked(game, (int)game->player.x, check_y))
		game->player.y = ny;
}

void	move_left(t_game *game)
{
	double	nx;
	double	ny;
	int		check_x;
	int		check_y;

	nx = game->player.x - game->player.plane_x * game->player.move_speed;
	ny = game->player.y - game->player.plane_y * game->player.move_speed;
	check_x = (int)(nx - game->player.plane_x * COLLI_DIST);
	check_y = (int)(ny - game->player.plane_y * COLLI_DIST);
	if (!is_blocked(game, check_x, (int)game->player.y))
		game->player.x = nx;
	if (!is_blocked(game, (int)game->player.x, check_y))
		game->player.y = ny;
}

void	move_right(t_game *game)
{
	double	nx;
	double	ny;
	int		check_x;
	int		check_y;

	nx = game->player.x + game->player.plane_x * game->player.move_speed;
	ny = game->player.y + game->player.plane_y * game->player.move_speed;
	check_x = (int)(nx + game->player.plane_x * COLLI_DIST);
	check_y = (int)(ny + game->player.plane_y * COLLI_DIST);
	if (!is_blocked(game, check_x, (int)game->player.y))
		game->player.x = nx;
	if (!is_blocked(game, (int)game->player.x, check_y))
		game->player.y = ny;
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
