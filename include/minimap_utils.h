/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:15:49 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/25 08:50:36 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_UTILS_H
# define MINIMAP_UTILS_H

# include "cub.h"

void	draw_line(t_display *d, t_line line, int color);
void	put_pixel(t_display *d, int x, int y, int color);

#endif