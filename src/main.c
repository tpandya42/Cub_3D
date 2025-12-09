<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:45:17 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/08 15:41:16 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> 14ccaea (in process I haven' pull)

#include "cub.h"
#include "dummy.h"//tmp

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


	(void) argc; //tmp
	(void) argv;//tmp
	//verify(argc, argv);
	init_init(&game);
	fill_dummy(&game);//change after parse
	load_dummy_text(&game);//when parsing this change for the load parser textures
	setup_ini_vect(&game.player, game.map.player_dir);
	if (!create_win(&game.display))
		return (1);
	mlx_loop_hook(game.display.mlx, render_scene, &game);
	mlx_hook(game.display.win, 17, 0, close_win, &game);
	mlx_hook(game.display.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.display.win, 3, 1L<<1, key_release, &game);
	DEBUG_LOG("Player position: (%.2f, %.2f)", game.player.x, game.player.y);
	DEBUG_LOG("Window size: %dx%d", WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(game.display.mlx);

	// verify(argc, argv);
	// init_struct(&game);
	// if (parse_map(&game, argv[1]))
	// {
	// 	ft_printf("Error\nFailed to parse map\n");
	// 	return (1);
	// }
	// ft_printf("✓ Map parsed successfully!\n");
	// ft_printf("  Textures:\n");
	// ft_printf("    NO: %s\n", game.textures.north);
	// ft_printf("    SO: %s\n", game.textures.south);
	// ft_printf("    WE: %s\n", game.textures.west);
	// ft_printf("    EA: %s\n", game.textures.east);
	// ft_printf("  Colors:\n");
	// ft_printf("    Floor: %d,%d,%d\n", game.floor.floor[0], game.floor.floor[1],
	// 	game.floor.floor[2]);
	// ft_printf("    Ceiling: %d,%d,%d\n", game.ceiling.ceiling[0],
	// 	game.ceiling.ceiling[1], game.ceiling.ceiling[2]);
	// ft_printf("  Map:\n");
	// ft_printf("    Rows: %d, Cols: %d\n", game.map.rows, game.map.cols);
	// ft_printf("    Player: (%d,%d) facing %c\n", game.map.player_x,
	// 	game.map.player_y, game.map.player_dir);
	// return (0);

}
