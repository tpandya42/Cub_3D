/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 16:21:30 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int	close_winx(t_display *disp)
{
	clean_exit(disp, 0);
	return (0);
}

void	*create_win(t_display *disp)
{
	char	*msg;

	msg = "MiniMap Debug";
	disp->win = mlx_new_window(disp->mlx, disp->win_w, disp->win_h, msg);
	if (!disp->win)
	{
		print_error("Error: creating a window");
		return (NULL);
	}
	return (disp->win);
}


void	ini_win(t_display *disp)
{
	disp->win_h = WIN_HEIGHT;
	disp->win_w = WIN_WIDTH;
	disp->move_count = 0;
}
