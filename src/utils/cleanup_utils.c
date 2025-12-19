/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:12:21 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/19 08:12:23 by tpandya          ###   ########.fr       */
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
