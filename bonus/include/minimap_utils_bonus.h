/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:26:52 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:26:54 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_UTILS_BONUS_H
# define MINIMAP_UTILS_BONUS_H

# include "cub.h"

void	draw_line(t_display *d, t_line line, int color);
void	put_pixel(t_display *d, int x, int y, int color);

#endif
