/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:41:13 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 08:43:20 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>

# ifdef DEBUG_MODE
#  define DEBUG_LOG(fmt, ...) \
    printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
# else
#  define DEBUG_LOG(fmt, ...) \
    do { } while (0)
# endif

#endif
