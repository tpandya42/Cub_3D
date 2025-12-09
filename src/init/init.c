/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:01:44 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/02 08:55:07 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	zero_display(t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->bpp = 0;
	display->line_len = 0;
	display->endian = 0;
	display->win_w = 0;
	display->win_h = 0;
	return (0);
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->path = NULL;
	map->total_lines = 0;
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
	player->x = 2.5;
	player->y = 2.5;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->rot_speed = ROT_SPEED;
	player->move_speed = M_SPEED;
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

void	init_struct(t_game *game)
{
	zero_display(&game->display);
	init_map(&game->map);
	init_player(&game->player);
	init_texture(&game->texture);
	init_render_tex(&game->rtex);
	init_color(&game->floor);
	init_color(&game->ceiling);
	init_key(&game->key);
	game->flags = 0;
}
