/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:28:12 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:28:15 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

# include "cub.h"

int		close_win(t_game *game);
void	*create_win(t_display *disp);
void	init_win(t_display *disp);

#endif
