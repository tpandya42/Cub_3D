/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:32 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 18:23:02 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MOVE_H
# define MOVE_H

# include "cub.h"

void	move_forward(t_game *game);
void	move_back(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	handle_movement(t_game *game);

#endif