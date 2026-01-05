/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:33:36 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:33:38 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->width = 0;
	texture->height = 0;
}

static void	init_wall_data(t_wall_data *wdata)
{
	wdata->img_ptr = NULL;
	wdata->addr = NULL;
	wdata->bpp = 0;
	wdata->line_len = 0;
	wdata->endian = 0;
	wdata->width = 0;
	wdata->height = 0;
}

void	init_render_tex(t_render_tex *rtex)
{
	init_wall_data(&rtex->north);
	init_wall_data(&rtex->south);
	init_wall_data(&rtex->west);
	init_wall_data(&rtex->east);
}
