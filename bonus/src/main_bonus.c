/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:33:10 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:33:12 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_player(t_game *game)
{
	game->player.ini_x = game->map.player_x + 0.5;
	game->player.ini_y = game->map.player_y + 0.5;
	game->player.x = game->player.ini_x;
	game->player.y = game->player.ini_y;
	setup_ini_vect(&game->player, game->map.player_dir);
}

static int	parse_and_prepare(t_game *game, char *path)
{
	if (parse_map(game, path))
	{
		clean_texture_paths(&game->texture);
		clean_map(&game->map);
		return (1);
	}
	init_player(game);
	init_minimap(game);
	return (0);
}

static int	init_graphics(t_game *game)
{
	if (init_display(&game->display))
		return (print_error("Error: failed to initialize display"), 1);
	if (load_textures(game))
		return (print_error("Error: failed to load textures"), 1);
	if (!create_win(&game->display))
		return (1);
	return (0);
}

static void	setup_hooks(t_game *game)
{
	mlx_loop_hook(game->display.mlx, render_scene, game);
	mlx_hook(game->display.win, 17, 0, close_win, game);
	mlx_hook(game->display.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->display.win, 3, 1L << 1, key_release, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	verify(argc, argv);
	init_struct(&game);
	if (parse_and_prepare(&game, argv[1]))
		return (1);
	if (init_graphics(&game))
		return (1);
	setup_hooks(&game);
	mlx_loop(game.display.mlx);
	return (0);
}
