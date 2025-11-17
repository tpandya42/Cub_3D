/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:29:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 17:28:52 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "dummy.h"
#include "render.h"


int	main(void)
{
	t_game	game;

	//PARSING
	init_init(&game);
	fill_dummy(&game);
	if (!create_win(&game.display))
		return (1);
	render_scene(&game);
	mlx_hook(game.display.win, 17, 0, close_win, &game);//events to close
	//mlx_key_hook(data.win, key_handle, &data);//events
	DEBUG_LOG("Player position: (%.2f, %.2f)", game.player.x, game.player.y);
	DEBUG_LOG("Window size: %dx%d", WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(game.display.mlx);
	return (0);
}