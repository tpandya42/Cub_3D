/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/12 08:00:28 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_win(t_game *game)
{
	clean_exit(game, 0);
	return (0);
}

void	*create_win(t_display *disp)
{
	char	*msg;

	msg = "Wonderland";
	disp->win = mlx_new_window(disp->mlx, disp->win_w, disp->win_h, msg);
	if (!disp->win)
	{
		print_error("Error: creating a window");
		return (NULL);
	}
	return (disp->win);
}


void	init_win(t_display *disp)
{
	disp->win_h = WIN_HEIGHT;
	disp->win_w = WIN_WIDTH;
}
