/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:29:18 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 18:22:15 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cub.h"

int		close_win(t_game *game);
void	*create_win(t_display *disp);
void	init_win(t_display *disp);

#endif
