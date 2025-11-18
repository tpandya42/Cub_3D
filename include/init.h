/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:45:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/18 16:07:02 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H	
# define INIT_H

# include "cub.h"

void	init_key(t_input_key *key);
void	init_minimap(t_game *game);
int		init_display(t_display *display);
void	init_player(t_player *player);
void	init_map(t_map *map);
void	init_color(t_color *color);
void	init_init(t_game *game);




#endif
