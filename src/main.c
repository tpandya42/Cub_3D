/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:45:17 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/28 18:59:38 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "dummy.h"//tmp

static int	map_extension_checker(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = ft_strlen(map) - 1;
	if (map[i] == 'b' && map[i - 1] == 'u'
		&& map[i - 2] == 'c' && map[i - 3] == '.')
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
}
