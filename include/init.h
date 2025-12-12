/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:45:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/28 14:54:52 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H	
# define INIT_H

# include "cub.h"

void	init_wall_data(t_wall_data *wdata);
void	init_render_tex(t_render_tex *rtex);
void	init_key(t_input_key *key);
void	init_minimap(t_game *game);
int		init_display(t_display *display);
int		zero_display(t_display *display);
void	init_player(t_player *player);
void	init_map(t_map *map);
void	init_texture(t_texture *texture);
void	init_color(t_color *color);
void	init_struct(t_game *game);

#endif
