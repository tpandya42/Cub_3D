/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_0_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:35:56 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:35:58 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
/* ========== FLOOD FILL ALGORITHM ========== */

static int	is_leak(t_flood *f, int r, int c)
{
	int	len;

	if (r < 0 || r >= f->rows)
		return (1);
	len = ft_strlen(f->grid[r]);
	if (c < 0 || c >= len)
		return (1);
	if (f->grid[r][c] == '\0' || f->grid[r][c] == '\n')
		return (1);
	return (0);
}

int	flood_check(t_flood *f, int r, int c)
{
	if (is_leak(f, r, c))
		return (1);
	if (f->grid[r][c] == '1' || f->visited[r][c])
		return (0);
	f->visited[r][c] = 1;
	if (flood_check(f, r + 1, c))
		return (1);
	if (flood_check(f, r - 1, c))
		return (1);
	if (flood_check(f, r, c + 1))
		return (1);
	if (flood_check(f, r, c - 1))
		return (1);
	return (0);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == '\n' || c == '\0');
}

/* ========== PLAYER POSITION VALIDATION ========== */

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
