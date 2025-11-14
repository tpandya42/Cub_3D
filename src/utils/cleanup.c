/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:09:53 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 16:21:53 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void clean_map(t_map *map)
{
	int	i;

	i = 0;
    if (!map || !map->grid)
        return;
    while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
    free(map->grid);
    map->grid = NULL;
}

void clean_textures(t_display *disp, t_texture *text)
{
    if (!disp || !disp->mlx || !text)
        return;

    if (text->north)
        mlx_destroy_image(disp->mlx, text->north);
    if (text->south)
        mlx_destroy_image(disp->mlx, text->south);
    if (text->east)
        mlx_destroy_image(disp->mlx, text->east);
    if (text->west)
        mlx_destroy_image(disp->mlx, text->west);

    text->north = NULL;
    text->south = NULL;
    text->east  = NULL;
    text->west  = NULL;
}

void clean_window(t_display *disp)
{
    if (disp->win)
    {
        mlx_destroy_window(disp->mlx, disp->win);
        disp->win = NULL;
    }
}

void clean_mlx(t_display *disp)
{
    if (disp->mlx)
    {
        mlx_destroy_display(disp->mlx);
        free(disp->mlx);
        disp->mlx = NULL;
    }
}

void clean_exit(t_game *game, int status)
{
    clean_map(&game->map);
    clean_textures(&game->disp, &game->text);
    clean_window(&game->disp);
    clean_mlx(&game->disp);

    exit(status);
}