/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:45:17 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/12 20:10:23 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

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
		ft_printf("Invalid Inputs\n");
		exit(1);
	}
	if (map_extension_checker(av[1]) == 0)
	{
		ft_printf("Invalid Map Extension\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Can't open file\n");
		exit(1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	verify(argc, argv);
	ft_printf("DEBUG: After verify\\n");
	init_struct(&game);
	ft_printf("DEBUG: After init_struct\\n");
	if (parse_map(&game, argv[1]))
	{
		ft_printf("Error\\nFailed to parse map\\n");
		return (1);
	}
	ft_printf("DEBUG: After parse_map - rows=%d cols=%d\\n", game.map.rows, game.map.cols);
	/* Set player starting position from parsed map data */
	ft_printf("DEBUG: player_x=%d player_y=%d dir=%c\\n", game.map.player_x, game.map.player_y, game.map.player_dir);
	game.player.ini_x = game.map.player_x + 0.5;
	game.player.ini_y = game.map.player_y + 0.5;
	game.player.x = game.player.ini_x;
	game.player.y = game.player.ini_y;
	ft_printf("DEBUG: Before init_minimap\\n");
	init_minimap(&game);
	ft_printf("DEBUG: After init_minimap\\n");
	/* Initialize display (mlx) before loading textures */
	if (init_display(&game.display))
	{
		ft_printf("Error\\nFailed to initialize display\\n");
		return (1);
	}
	ft_printf("DEBUG: After init_display\\n");
	/* Load textures from parsed paths */
	ft_printf("DEBUG: Texture paths: N=%s S=%s\\n", game.texture.north, game.texture.south);
	if (load_textures(&game))
	{
		ft_printf("Error\\nFailed to load textures\\n");
		return (1);
	}
	ft_printf("DEBUG: After load_textures\\n");
	setup_ini_vect(&game.player, game.map.player_dir);
	ft_printf("DEBUG: After setup_ini_vect\\n");
	if (!create_win(&game.display))
		return (1);
	ft_printf("DEBUG: After create_win\\n");
	mlx_loop_hook(game.display.mlx, render_scene, &game);
	ft_printf("DEBUG: After mlx_loop_hook\\n");
	mlx_hook(game.display.win, 17, 0, close_win, &game);
	mlx_hook(game.display.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.display.win, 3, 1L<<1, key_release, &game);
	ft_printf("DEBUG: Before mlx_loop\\n");
	DEBUG_LOG("Player position: (%.2f, %.2f)", game.player.x, game.player.y);
	DEBUG_LOG("Window size: %dx%d", WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(game.display.mlx);
	return (0);
}
