/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:35:42 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:35:43 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* ========== MAP CHARACTER VALIDATION ========== */
int	check_chars(t_game *game)
{
	int		r;
	int		c;
	char	**grid;

	grid = game->map.grid;
	r = 0;
	while (r < game->map.rows)
	{
		c = 0;
		while (grid[r][c])
		{
			if (!is_valid_map_char(grid[r][c]))
			{
				print_error("Error: Invalid character in map");
				return (0);
			}
			c++;
		}
		r++;
	}
	return (1);
}

int	check_player_not_on_edge(t_game *game)
{
	int	px;
	int	py;
	int	len;

	px = game->map.player_x;
	py = game->map.player_y;
	len = ft_strlen(game->map.grid[py]);
	if (py == 0 || py == game->map.rows - 1)
	{
		print_error("Error: Player cannot be on map edge (top/bottom)");
		return (0);
	}
	if (px == 0 || px >= len - 1)
	{
		print_error("Error: Player cannot be on map edge (left/right)");
		return (0);
	}
	return (1);
}
