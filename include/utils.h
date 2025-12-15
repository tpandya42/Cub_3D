/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:29:27 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 17:29:32 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub.h"

/* Error handling */
void	print_error(char *msg);

/* Cleanup functions */
void	clean_map(t_map *map);
void	clean_texture_paths(t_texture *tex);
void	clean_render_textures(t_display *disp, t_render_tex *rtex);
void	clean_window(t_display *disp);
void	clean_mlx(t_display *disp);
void	clean_exit(t_game *game, int status);

/* Texture loading */
int		load_textures(t_game *game);

#endif
