/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:34:09 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:34:10 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
