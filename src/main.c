/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:14:39 by tpandya           #+#    #+#             */
/*   Updated: 2025/11/20 01:14:42 by tpandya          ###   ########.fr       */
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
	init_struct(&game);
	if (parse_map(&game, argv[1]))
	{
		ft_printf("Error\nFailed to parse map\n");
		return (1);
	}
	ft_printf("✓ Map parsed successfully!\n");
	ft_printf("  Textures:\n");
	ft_printf("    NO: %s\n", game.textures.north);
	ft_printf("    SO: %s\n", game.textures.south);
	ft_printf("    WE: %s\n", game.textures.west);
	ft_printf("    EA: %s\n", game.textures.east);
	ft_printf("  Colors:\n");
	ft_printf("    Floor: %d,%d,%d\n", game.floor.floor[0], game.floor.floor[1],
		game.floor.floor[2]);
	ft_printf("    Ceiling: %d,%d,%d\n", game.ceiling.ceiling[0],
		game.ceiling.ceiling[1], game.ceiling.ceiling[2]);
	ft_printf("  Map:\n");
	ft_printf("    Rows: %d, Cols: %d\n", game.map.rows, game.map.cols);
	ft_printf("    Player: (%d,%d) facing %c\n", game.map.player_x,
		game.map.player_y, game.map.player_dir);
	return (0);
}
