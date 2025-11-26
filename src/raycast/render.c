/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:38:05 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/26 15:36:56 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
