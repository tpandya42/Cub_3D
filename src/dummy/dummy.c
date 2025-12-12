/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:39:29 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/12 20:07:54 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "dummy.h"

void	load_text(t_game *game, t_wall_data *wall_data, char *path)
{
	wall_data->img_ptr = mlx_xpm_file_to_image(game->display.mlx,
			path, &wall_data->width, &wall_data->height);
	if (!wall_data->img_ptr)
		print_error("Error loading texture");
	wall_data->addr = 
		mlx_get_data_addr(wall_data->img_ptr, &wall_data->bpp,
			&wall_data->line_len, &wall_data->endian);
}

void	load_dummy_text(t_game *game)
{
	//game->texture.north = "textures/dark_north.xpm";
	//game->texture.south = "textures/dark_south.xpm";
	//game->texture.west = "textures/dark_west.xpm";
	//game->texture.east = "textures/dark_east.xpm";
	game->texture.north = "textures/sweet_no.xpm";
	game->texture.south = "textures/sweet_so.xpm";
	game->texture.west = "textures/sweet_we.xpm";
	game->texture.east = "textures/sweet_ea.xpm";
	load_text(game, &game->rtex.north, game->texture.north);
	load_text(game, &game->rtex.south, game->texture.south);
	load_text(game, &game->rtex.west, game->texture.west);
	load_text(game, &game->rtex.east, game->texture.east);
}

void	fill_colors(t_game *game)
{
	// floor gray
	game->floor.floor[0] = 128;
	game->floor.floor[1] = 128;
	game->floor.floor[2] = 128;

	// ceiling light blue
	game->ceiling.ceiling[0] = 135;
	game->ceiling.ceiling[1] = 206;
	game->ceiling.ceiling[2] = 250;
}

void	dummy_map(t_game *game)
{
	static char	*dummy_map[10] = {
		"1111111111",
		"1000000001",
		"1011111101",
		"1000000001",
		"1011111101",
		"1001000001",
		"1011111101",
		"1000000001",
		"1111111111",
		"1111111111"
	};
	game->map.rows = 10;
	game->map.cols = 10;
	game->map.map = dummy_map;
}

void	dummy_player(t_game *game)
{
	game->player.ini_x = 1.5;
	game->player.ini_y = 1.5;
	game->player.x = game->player.ini_x;
	game->player.y = game->player.ini_y;
}

void	fill_dummy(t_game *game)
{
	fill_colors(game);
	dummy_map(game);
	dummy_player(game);
}
