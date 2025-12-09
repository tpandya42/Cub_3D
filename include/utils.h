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

void	print_error(char *msg);
void	clean_exit(t_game *game, int status);
int		load_textures(t_game *game);

#endif
