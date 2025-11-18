/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:51:06 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/18 17:30:08 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// --- ANSI reset and style codes --- //
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"

/*
 * RED:       Error/critical warnings
 * GREEN:     Prompt/success messages
 * YELLOW:    warnings/debug
 * BLUE:      info messages
 * MAGENTA:   Execution debug
 * CYAN:      FD, Parsing and Tokenization Debug
 */
// --- Text colors --- //
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

// Minimap defaults
# define COLOR_WALL      0x333333
# define COLOR_EMPTY     0xAAAAAA
# define COLOR_PLAYER    0xFF8800
# define COLOR_RAY       0xFFFF00
# define COLOR_FLOOR     0x202020

#endif // COLORS_H
