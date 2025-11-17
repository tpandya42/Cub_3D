/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:53:43 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 16:36:10 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/libft.h"//do we need this?
# include "../minilibx-linux/mlx.h"//do we need this?
# include <X11/X.h>//do we need this?
# include <X11/keysym.h>//do we need this?

// Own headers
# include "struct.h"
# include "colors.h"
# include "init.h"
# include "window.h"
# include "minimap.h"
# include "raycast.h"
# include "utils.h"

//Bonus headers
# include "minimap.h"

//Debug headers
# include "debug.h"

#endif
