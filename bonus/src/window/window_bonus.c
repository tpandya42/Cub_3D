/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:38:12 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:38:13 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_win(t_display *disp)
{
	disp->win_w = WIN_WIDTH;
	disp->win_h = WIN_HEIGHT;
	disp->win = NULL;
	disp->img = NULL;
	disp->addr = NULL;
	disp->bpp = 0;
	disp->line_len = 0;
	disp->endian = 0;
}

void	*create_win(t_display *disp)
{
	disp->win = mlx_new_window(disp->mlx, disp->win_w, disp->win_h, "cub3D");
	if (!disp->win)
	{
		print_error("Error: Unable to create window");
		return (NULL);
	}
	return (disp->win);
}

int	close_win(t_game *game)
{
	clean_exit(game, 0);
	return (0);
}
