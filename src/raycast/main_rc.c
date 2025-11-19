/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:29:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 17:45:07 by albetanc         ###   ########.fr       */
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
	setup_ini_vect(&game.player, game.map.player_dir);
	if (!create_win(&game.display))
		return (1);
	//render_scene(&game);
	//mlx_key_hook(game.display.win, render_scene, &game);//main loop
	mlx_loop_hook(game.display.mlx, render_scene, &game);
	mlx_hook(game.display.win, 17, 0, close_win, &game);//close the window
	//mlx_key_hook(game.display.win, key_press, &game);//events mlx hook when pressing a key not if keey press
	mlx_hook(game.display.win, 2, 1L<<0, key_press, &game);//to keep it press
	mlx_hook(game.display.win, 3, 1L<<1, key_release, &game);//smooth
	DEBUG_LOG("Player position: (%.2f, %.2f)", game.player.x, game.player.y);
	DEBUG_LOG("Window size: %dx%d", WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(game.display.mlx);
	return (0);
}