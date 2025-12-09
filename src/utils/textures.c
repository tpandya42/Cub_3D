/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:00:00 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/09 12:00:00 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	load_single_texture(t_game *game, t_wall_data *wall_data,
				char *path)
{
	if (!path)
	{
		print_error("Error: texture path is NULL");
		return (1);
	}
	wall_data->img_ptr = mlx_xpm_file_to_image(game->display.mlx,
			path, &wall_data->width, &wall_data->height);
	if (!wall_data->img_ptr)
	{
		print_error("Error: failed to load texture");
		return (1);
	}
	wall_data->addr = mlx_get_data_addr(wall_data->img_ptr, &wall_data->bpp,
			&wall_data->line_len, &wall_data->endian);
	if (!wall_data->addr)
	{
		print_error("Error: failed to get texture data");
		return (1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_single_texture(game, &game->rtex.north, game->texture.north))
		return (1);
	if (load_single_texture(game, &game->rtex.south, game->texture.south))
		return (1);
	if (load_single_texture(game, &game->rtex.west, game->texture.west))
		return (1);
	if (load_single_texture(game, &game->rtex.east, game->texture.east))
		return (1);
	return (0);
}
