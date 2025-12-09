/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:09:53 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/28 15:16:36 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clean_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	if (map->path)
	{
		free(map->path);
		map->path = NULL;
	}
}

void	clean_texture_paths(t_texture *tex)
{
	if (!tex)
		return ;
	if (tex->north)
	{
		free(tex->north);
		tex->north = NULL;
	}
	if (tex->south)
	{
		free(tex->south);
		tex->south = NULL;
	}
	if (tex->west)
	{
		free(tex->west);
		tex->west = NULL;
	}
	if (tex->east)
	{
		free(tex->east);
		tex->east = NULL;
	}
}

static void	clean_wall_data(t_display *disp, t_wall_data *wd)
{
	if (wd->img_ptr)
	{
		mlx_destroy_image(disp->mlx, wd->img_ptr);
		wd->img_ptr = NULL;
	}
}

void	clean_render_textures(t_display *disp, t_render_tex *rtex)
{
	if (!disp || !disp->mlx || !rtex)
		return ;
	clean_wall_data(disp, &rtex->north);
	clean_wall_data(disp, &rtex->south);
	clean_wall_data(disp, &rtex->west);
	clean_wall_data(disp, &rtex->east);
}

void	clean_window(t_display *disp)
{
	if (!disp)
		return ;
	if (disp->win)
	{
		mlx_destroy_window(disp->mlx, disp->win);
		disp->win = NULL;
	}
}

void	clean_mlx(t_display *disp)
{
	if (!disp || !disp->mlx)
		return ;
	mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	disp->mlx = NULL;
}

void	clean_exit(t_game *game, int status)
{
	if (!game)
		exit(status);
	if (game->display.img && game->display.mlx)
		mlx_destroy_image(game->display.mlx, game->display.img);
	clean_render_textures(&game->display, &game->rtex);
	clean_texture_paths(&game->texture);
	clean_window(&game->display);
	clean_mlx(&game->display);
	clean_map(&game->map);
	exit(status);
}
