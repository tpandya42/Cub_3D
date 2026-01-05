/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:26:33 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:26:35 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_BONUS_H
# define KEYS_BONUS_H

# include "cub.h"

# ifdef __APPLE__
#  define KEY_W       13
#  define KEY_A       0
#  define KEY_S       1
#  define KEY_D       2

#  define KEY_Q       12
#  define KEY_E       14

#  define KEY_LEFT    123
#  define KEY_RIGHT   124
#  define KEY_UP      126
#  define KEY_DOWN    125

#  define KEY_ESC     53
# else
#  define KEY_W       119
#  define KEY_A       97
#  define KEY_S       115
#  define KEY_D       100

#  define KEY_LEFT    65361
#  define KEY_RIGHT   65363
#  define KEY_UP      65362
#  define KEY_DOWN    65364

#  define KEY_Q       113
#  define KEY_E       101

#  define KEY_ESC     65307

# endif

#endif
