/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:16 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/03 19:36:52 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	get_wall_sampler(t_sampler *sam, t_game *game, t_ray *ray, t_wall wall)//new
{
	double	hit;

	// same hit calculation
	if (ray->side == 0)
		hit = game->player.y + ray->wall_dist * ray->diry;
	else
		hit = game->player.x + ray->wall_dist * ray->dirx;
	hit -= ft_floor(hit);
	sam->tex_x = (int)(hit * wall.tex->width);
	if ((ray->side == 0 && ray->step_x > 0)
		|| (ray->side == 1 && ray->step_y < 0))
		sam->tex_x = wall.tex->width - sam->tex_x - 1;
	sam->step = (double)wall.tex->height / (wall.wall_end - wall.wall_start);
	sam->tex_pos = (wall.wall_start - game->display.win_h / 2 
			+ (wall.wall_end - wall.wall_start) / 2) * sam->step;
}

//int	get_wall_face(t_ray *ray)
//{
//	//vertical (E/W)
//	if (ray->side == 0)
//	{
//		if (ray->step_x > 0)
//			return (0xBA8E23);//E
//		else
//			return (0x4B4B4B);//W
//	}
//	else//horizontal (N/S)
//	{
//		if (ray->step_y > 0)
//			return (0x800080);//S
//		else
//			return (0x008080);//N
//	}
//}

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

//later this should be get_texture_color
//static int	get_color_wall(int y, t_wall data, t_ray *ray)
//{
//	//sky
//	if (y < data.wall_start)
//		return (0x87CEEB);
//	//wall
//	else if (y >= data.wall_start && y <= data.wall_end)
//		return (0x8FBC8F);
//	else
//	//floor
//		return (0xA0522D);
//}

static void	draw_col(t_game *game, t_wall data, t_ray *ray)
{
	int			y;
	int			color;
	int			tex_y;
	t_sampler	sam;

	get_wall_sampler(&sam, game, ray, data);
	y = 0;
	//while (y < WIN_HEIGHT)
	while (y < game->display.win_h)
	{
		 if (y < data.wall_start)//new
			color = ceiling_color(game);//new
		else if (y > data.wall_end)//new
			color = floor_color(game);//new
		else//new
		{
			tex_y = (int)sam.tex_pos & (data.tex->height - 1);//new
			sam.tex_pos += sam.step;//new
			color = sample_texture(data.tex, sam.tex_x, tex_y);
		}
		//color = get_wall_color(y, data, ray);
		my_mlx_pixel_put(&game->display, data.col, y, color);
		y++;
	}
}

void	render_wall(t_game *game, int col, t_ray *ray)
{
	int		wall_hei;
	t_wall	data;
	//int	wall_start;
	//int	wall_end;

	wall_hei = (int)(game->display.win_h / ray->wall_dist);//wall size
	data.wall_start = -wall_hei / 2 + game->display.win_h / 2;
	if (data.wall_start < 0)
		data.wall_start = 0;
	data.wall_end = wall_hei / 2 + game->display.win_h / 2;
	if (data.wall_end >= game->display.win_h)
		data.wall_end = game->display.win_h -1;
	data.tex = get_wall_face(game, ray);//new
	data.col = col;
	draw_col(game, data, ray);//in progress
}
