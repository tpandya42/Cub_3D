/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:26:24 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:26:26 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H	
# define INIT_BONUS_H

# include "cub.h"

void	init_render_tex(t_render_tex *rtex);
void	init_key(t_input_key *key);
void	init_minimap(t_game *game);
int		init_display(t_display *display);
void	init_texture(t_texture *texture);
void	init_color(t_color *color);
void	init_struct(t_game *game);

#endif
