/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:51:27 by albetanc          #+#    #+#             */
/*   Updated: 2025/12/08 17:19:22 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

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
 
 #  define KEY_P       112//tmp debbug

#  define KEY_LEFT    65361
#  define KEY_RIGHT   65363
#  define KEY_UP      65362
#  define KEY_DOWN    65364

#  define KEY_Q       113
#  define KEY_E       101

#  define KEY_ESC     65307

# endif

#endif
