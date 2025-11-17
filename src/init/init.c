/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:01:44 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 17:41:30 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->player_dir = '\0';
}

void	init_player(t_player *player)
{
	player->ini_x = 0;
	player->ini_y = 0;
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->rot_speed = 0;
	player->move_speed = 0;
}

void	init_texture(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->width = 0;
	texture->height = 0;
}

void	init_color(t_color *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color->floor[i] = 0;
		color->ceiling[i] = 0;
		i++;
	}
}

void	init_init(t_game *game)
{
	init_display(&game->display);
	init_map(&game->map);
	init_player(&game->player);
	init_texture(&game->textures);
	init_color(&game->floor);
	init_color(&game->ceiling);
	init_minimap(game);
	game->flags = 0;
}
