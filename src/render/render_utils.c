/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:11 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/13 10:45:37 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	create_rgb(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}

int	ceiling_color(t_game *game)
{
	int	r;
	int	g;
	int	b;

	r = game->ceiling.ceiling[0];
	g = game->ceiling.ceiling[1];
	b = game->ceiling.ceiling[2];
	return (create_rgb(r, g, b));
}

int	floor_color(t_game *game)
{
	int	r;
	int	g;
	int	b;

	r = game->floor.floor[0];
	g = game->floor.floor[1];
	b = game->floor.floor[2];
	return (create_rgb(r, g, b));
}

int	sample_texture(t_wall_data *tex, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	color = *(int *)pixel;
	return (color);
}
