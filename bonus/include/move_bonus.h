/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:27:01 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:27:02 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_BONUS_H
# define MOVE_BONUS_H

# include "cub.h"

void	move_forward(t_game *game);
void	move_back(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	handle_movement(t_game *game);

#endif
