/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:38:05 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 18:08:42 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render_scene(t_game *game)
{
	size_t buffer_size;

	buffer_size = game->display.win_w 
		* game->display.win_h * (game->display.bpp / 8);
	ft_memset(game->display.addr, 0, buffer_size);
	handle_movement(game);
	//render_raycast(game);
	draw_minimap(game);
	draw_player_minimap(game);
	draw_player_ray(game);//in progress
	//handle_movement(game);
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
	//if (keycode == 65362 || keycode == 'w')
	//	game->key.forward = 0;
	//else if (keycode == 65364 || keycode == 's')
	//	game->key.back = 0;
	//else if (keycode == 65361 || keycode == 'a')
	//	game->key.left = 0;
	//else if (keycode == 65363 || keycode == 'd')
	//	game->key.right = 0;
	//else if (keycode == 24 || keycode == 'q')
	//	game->key.rot_left = 0;
	//else if (keycode == 26 || keycode == 'e')
	//	game->key.rot_right = 0;
	//return (0);
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
	////MacOS keycode = 123
	//if (keycode == 65361 || keycode == 'a')
	//	//move_left(game);
	//	game->key.left = 1;
	////MacOS keycode = 124
	//else if (keycode == 65363 || keycode == 'd')
	//	//move_right(game);
	//	game->key.right = 1;
	////MacOS keycode = 126
	//else if (keycode == 65362 || keycode == 'w')
	//	//move_forward(game);
	//	game->key.forward = 1;
	////MacOS keycode = 125
	//else if (keycode == 65364 || keycode == 's')
	//	//move_back(game);
	//	game->key.back = 1;
	////MacOS keycode = 53
	//if (keycode == 65307)
	//	close_esc(game);
	////MacOS keycode = 12
	//if (keycode == 24 || keycode == 'q')
	//	//rotate_left(game);
	//	game->key.rot_left = 1;
	////MacOS keycode = 14
	//if (keycode == 26 || keycode == 'e')
	//	//rotate_right(game);
	//	game->key.rot_right = 1;
	//mlx_clear_window(game->display.mlx, game->display.win);
	//render_scene(game);
	//mlx_loop_hook(game->display.mlx, render_scene, game);//new
	return (0);
}
