/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/09 18:29:07 by albetanc         ###   ########.fr       */
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

//void	get_wall_sampler(t_sampler *sam, t_game *game, t_ray *ray, t_wall wall)
//{
//	double hit = ray->hit;//new
//	if (hit >= 1.0)//new
//		hit = 1.0 - EPSILON;//new
//	sam->tex_x = (int)(hit * wall.tex->width);
//	if ((ray->side == 0 && ray->step_x > 0)
//		|| (ray->side == 1 && ray->step_y < 0))
//		sam->tex_x = wall.tex->width - sam->tex_x - 1;

//	sam->step = (double)wall.tex->height / (wall.wall_end - wall.wall_start);
//	sam->tex_pos = (wall.wall_start - game->display.win_h / 2
//			+ (wall.wall_end - wall.wall_start) / 2) * sam->step;
//}
void	get_wall_sampler(t_sampler *sam, t_game *game, t_ray *ray, t_wall wall)
{
	double wall_height_unclamped;//change ame
	double hit;

	hit = ray->hit;
	if (hit >= 1.0)
		hit = 1.0 - EPSILON;
	
	sam->tex_x = (int)(hit * wall.tex->width);

	if ((ray->side == 0 && ray->step_x > 0)
		|| (ray->side == 1 && ray->step_y < 0))
		sam->tex_x = wall.tex->width - sam->tex_x - 1;

	sam->step = (double)wall.tex->height / (wall.wall_end - wall.wall_start);
	
	wall_height_unclamped = (double)game->display.win_h / ray->wall_dist;
	
	sam->tex_pos = (wall.wall_start - ((double)game->display.win_h / 2.0 - wall_height_unclamped / 2.0)) * sam->step;
}


t_wall_data	*get_wall_face(t_game *game, t_ray *ray)
{
	if (ray->side == 0)//vertical (E/W)
	{
		if (ray->step_x > 0)
			return (&game->rtex.east);
		else
			return (&game->rtex.west);
	}
	else
	{
		if (ray->step_y > 0)//hrz (N/S)
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
