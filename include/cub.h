/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:53:43 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 18:18:58 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// headers
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/libft.h"//check
# include "../minilibx-linux/mlx.h"//check
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

// Own headers
# include "struct.h"
# include "defines.h"
# include "colors.h"
# include "init.h"
# include "window.h"
# include "utils.h"
# include "display.h"
# include "minimap.h"
# include "player.h"
# include "move.h"
# include "rotation.h"
# include "keys.h"
# include "raycast.h"

//Bonus headers
# include "minimap.h"

//Debug headers
# include "debug.h"

#endif
