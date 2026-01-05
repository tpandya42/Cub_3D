/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:28:06 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:28:07 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

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
int		map_extension_checker(char *map);
int		verify(int argc, char **argv);
/* Texture loading */
int		load_textures(t_game *game);

#endif
