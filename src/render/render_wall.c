/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/12 20:07:29 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define EPSILON 1e-6

double	ft_floor(double x)
{
	long long	truncated_int;

	truncated_int = (long long)x;
	if (x >= 0.0)
		return ((double)truncated_int);
	else if ((double)truncated_int != x)
		return ((double)(truncated_int - 1));
	else
		return ((double)truncated_int);
}

void	get_wall_sampler(t_sampler *sam, t_game *game, t_ray *ray, t_wall wall)
{
	double	hit;
	double	r_wall_hei;
	double	draw_start;

	hit = ray->hit;
	if (hit >= 1.0)
		hit = 1.0 - EPSILON;
	sam->tex_x = (int)(hit * wall.tex->width);
	if ((ray->side == 0 && ray->step_x > 0)
		|| (ray->side == 1 && ray->step_y < 0))
		sam->tex_x = wall.tex->width - sam->tex_x - 1;
	r_wall_hei = (double)game->display.win_h / ray->wall_dist;
	sam->step = (double)wall.tex->height / r_wall_hei;
	draw_start = game->display.win_h / 2.0 - r_wall_hei / 2.0;
	sam->tex_pos = (wall.wall_start - draw_start) * sam->step;
}


/*
* ray->side == 0 is vertical E/W
* ray->step_y > 0 is hrz N/S
*/
t_wall_data	*get_wall_face(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->rtex.east);
		else
			return (&game->rtex.west);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->rtex.south);
		else
			return (&game->rtex.north);
	}
}

static void	draw_col(t_game *game, t_wall data, t_ray *ray)
{
	int			y;
	int			color;
	int			tex_y;
	t_sampler	sam;

	get_wall_sampler(&sam, game, ray, data);
	y = 0;
	while (y < game->display.win_h)
	{
		if (y < data.wall_start)
			color = ceiling_color(game);
		else if (y > data.wall_end)
			color = floor_color(game);
		else
		{
			tex_y = (int)sam.tex_pos & (data.tex->height - 1);
			sam.tex_pos += sam.step;
			color = sample_texture(data.tex, sam.tex_x, tex_y);
		}
		my_mlx_pixel_put(&game->display, data.col, y, color);
		y++;
	}
}

void	render_wall(t_game *game, int col, t_ray *ray)
{
	int		wall_hei;
	t_wall	data;

	wall_hei = (int)(game->display.win_h / ray->wall_dist);
	data.wall_start = -wall_hei / 2 + game->display.win_h / 2;
	if (data.wall_start < 0)
		data.wall_start = 0;
	data.wall_end = wall_hei / 2 + game->display.win_h / 2;
	if (data.wall_end >= game->display.win_h)
		data.wall_end = game->display.win_h -1;
	data.tex = get_wall_face(game, ray);
	data.col = col;
	draw_col(game, data, ray);
}
