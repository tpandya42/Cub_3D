/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:38:05 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/08 18:29:35 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// prototypes from render_wall.c
t_wall_data	*get_wall_face(t_game *game, t_ray *ray);
void		get_wall_sampler(t_sampler *sam, t_game *game, t_ray *ray, t_wall wall);

static void
dump_debug_snapshot(t_game *game)//tmp for debbug
{
	int center;
	int col;
	int start;
	int end;
	t_ray ray;
	t_wall_data *tex;
	double hit;

	fprintf(stderr, "[DEBUG SNAPSHOT] Player: pos=(%.3f, %.3f) dir=(%.3f, %.3f)\n",
		game->player.x, game->player.y, game->player.dir_x, game->player.dir_y);
	center = game->display.win_w / 2;
	start = center - 10;
	end = center + 10;
	if (start < 0) start = 0;
	if (end >= game->display.win_w) end = game->display.win_w - 1;
	for (col = start; col <= end; col++)
	{
		ray = raycast(game, col);
		tex = get_wall_face(game, &ray);
		if (ray.side == 0)
			hit = game->player.y + ray.wall_dist * ray.diry;
		else
			hit = game->player.x + ray.wall_dist * ray.dirx;
		hit -= floor(hit);
		/* build temp wall to compute sampler */
		{
			t_wall wall;
			t_sampler sam;
			int wall_hei = (int)(game->display.win_h / ray.wall_dist);
			wall.wall_start = -wall_hei / 2 + game->display.win_h / 2;
			if (wall.wall_start < 0)
				wall.wall_start = 0;
			wall.wall_end = wall_hei / 2 + game->display.win_h / 2;
			if (wall.wall_end >= game->display.win_h)
				wall.wall_end = game->display.win_h - 1;
			wall.tex = tex;
			get_wall_sampler(&sam, game, &ray, wall);
			/* determine face name */
			const char *face_name = "?";
			if (tex == &game->rtex.east) face_name = "EAST";
			else if (tex == &game->rtex.west) face_name = "WEST";
			else if (tex == &game->rtex.north) face_name = "NORTH";
			else if (tex == &game->rtex.south) face_name = "SOUTH";
			fprintf(stderr,
				"[RAY] col=%3d dir=(% .4f,% .4f) side=%d step=(%d,%d) side_xy=(%.6f,%.6f) map=(%d,%d) dist=%.6f hit=%.6f tex_x=%d tex_pos=%.4f face=%s tex_ptr=%p img_ptr=%p addr=%p tex_w=%d tex_h=%d bpp=%d line_len=%d endian=%d\n",
				col, ray.dirx, ray.diry, ray.side, ray.step_x, ray.step_y,
				ray.side_x, ray.side_y, ray.current_x, ray.current_y, ray.wall_dist,
				hit, sam.tex_x, sam.tex_pos, face_name, (void *)tex, tex->img_ptr, (void *)tex->addr,
				tex->width, tex->height, tex->bpp, tex->line_len, tex->endian);
		}
	}
}

static void	render_raycast(t_game *game)
{
	t_ray	ray;
	int		col;

	col = 0;//doesn't matter the player position
	while (col < game->display.win_w)//to limit # of ray
	{
		ray = raycast(game, col);
		render_wall(game, col, &ray);
		col++;
	}
}


int	render_scene(t_game *game)
{
	size_t	buffer_size;

	buffer_size = game->display.win_w 
		* game->display.win_h * (game->display.bpp / 8);
	ft_memset(game->display.addr, 0, buffer_size);
	handle_movement(game);
	render_raycast(game);
	render_minimap(game);
	mlx_put_image_to_window(game->display.mlx, 
		game->display.win, game->display.img, 0, 0);
	return (0);
}

static void	close_esc(t_game *game)
{
	clean_exit(game, 0);
	exit(0);
}

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key.forward = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key.back = 0;
	else if (keycode == KEY_A)
		game->key.left = 0;
	else if (keycode == KEY_D)
		game->key.right = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_Q)
		game->key.rot_left = 0;
	else if (keycode == KEY_RIGHT || keycode == KEY_E)
		game->key.rot_right = 0;
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key.forward = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key.back = 1;
	else if (keycode == KEY_P)
		dump_debug_snapshot(game);
	else if (keycode == KEY_A)
		game->key.left = 1;
	else if (keycode == KEY_D)
		game->key.right = 1;
	else if (keycode == KEY_LEFT || keycode == KEY_Q)
		game->key.rot_left = 1;
	else if (keycode == KEY_RIGHT || keycode == KEY_E)
		game->key.rot_right = 1;
	else if (keycode == KEY_ESC)
		close_esc(game);
	return (0);
}
