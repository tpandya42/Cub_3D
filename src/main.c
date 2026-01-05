/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:45:17 by albetanc          #+#    #+#             */
/*   Updated: 2026/01/05 08:27:06 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	map_extension_checker(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = ft_strlen(map) - 1;
	if (map[i] == 'b' && map[i - 1] == 'u' && map[i - 2] == 'c' && map[i
			- 3] == '.')
		return (1);
	return (0);
}

int	verify(int argc, char **av)
{
	int	fd;

	if (argc != 2)
	{
		print_error("Error: Invalid Inputs");
		exit(1);
	}
	if (map_extension_checker(av[1]) == 0)
	{
		print_error("Error: Invalid Map Extension");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		print_error("Error: Can't open file");
		exit(1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	verify(argc, argv);
	init_struct(&game);
	if (parse_map(&game, argv[1]))
	{
		clean_texture_paths(&game.texture);
		clean_map(&game.map);
		return (print_error("Error: failed to parse map"), 1);
	}
	game.player.ini_x = game.map.player_x + 0.5;
	game.player.ini_y = game.map.player_y + 0.5;
	game.player.x = game.player.ini_x;
	game.player.y = game.player.ini_y;
	init_minimap(&game);
	if (init_display(&game.display))
		return (print_error("Error: failed to initialize display"), 1);
	if (load_textures(&game))
		return (print_error("Error: failed to load textures"), 1);
	setup_ini_vect(&game.player, game.map.player_dir);
	if (!create_win(&game.display))
		return (1);
	mlx_loop_hook(game.display.mlx, render_scene, &game);
	mlx_hook(game.display.win, 17, 0, close_win, &game);
	mlx_hook(game.display.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.display.win, 3, 1L << 1, key_release, &game);
	mlx_loop(game.display.mlx);
	return (0);
}
