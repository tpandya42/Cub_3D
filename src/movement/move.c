/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:49:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/17 17:34:37 by albetanc         ###   ########.fr       */
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
