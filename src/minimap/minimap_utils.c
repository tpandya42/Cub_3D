/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:16:01 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/25 08:53:46 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_line_loop(t_display *d, t_line *line, int color)
{
	int	e2;

	while (1)
	{
		put_pixel(d, line->x0, line->y0, color); // Draw the pixel

		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		e2 = 2 * line->err;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			line->x0 += line->sx;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			line->y0 += line->sy;
		}
	}
}

void	draw_line(t_display *d, t_line line_pts, int color)
{
	t_line	line;

	line.x0 = line_pts.x0;
	line.y0 = line_pts.y0;
	line.x1 = line_pts.x1;
	line.y1 = line_pts.y1;
	line.dx = abs(line.x1 - line.x0);
	line.dy = abs(line.y1 - line.y0);
	if (line.x0 < line.x1)
		line.sx = 1;
	else
		line.sx = -1;
	if (line.y0 < line.y1)
		line.sy = 1;
	else
		line.sy = -1;
	line.err = line.dx - line.dy;

	draw_line_loop(d, &line, color);
}


void	put_pixel(t_display *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= d->win_w || y >= d->win_h)
		return ;

	dst = d->addr + (y * d->line_len + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

