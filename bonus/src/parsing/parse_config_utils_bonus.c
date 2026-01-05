/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:34:56 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:34:58 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* ========== PLAYER POSITION DETECTION ========== */
static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player(t_game *game, int r, int c)
{
	game->map.player_x = c;
	game->map.player_y = r;
	game->map.player_dir = game->map.grid[r][c];
}

static int	player_s(t_game *game)
{
	int	r;
	int	c;
	int	count;

	r = 0;
	count = 0;
	while (r < game->map.rows)
	{
		c = 0;
		while (game->map.grid[r][c])
		{
			if (is_player(game->map.grid[r][c]))
			{
				set_player(game, r, c);
				count++;
			}
			c++;
		}
		r++;
	}
	return (count);
}

int	find_player_position(t_game *game)
{
	int	count;

	count = player_s(game);
	if (count == 0)
		return (print_error("Error: No player start position found"), 0);
	if (count > 1)
		return (print_error("Error: Multiple player positions found"), 0);
	return (1);
}

/* ========== MAIN PROCESSING FUNCTION ========== */

int	get_max_width(char **lines, int map_start, int rows)
{
	int	r;
	int	len;
	int	cmax;

	cmax = 0;
	r = 0;
	while (r < rows)
	{
		len = ft_strlen(lines[map_start + r]);
		if (len > 0 && lines[map_start + r][len - 1] == '\n')
			len--;
		if (len > cmax)
			cmax = len;
		r++;
	}
	return (cmax);
}
