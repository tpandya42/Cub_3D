/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:49:24 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/19 08:49:26 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* ========== MAP ENCLOSURE VALIDATION ========== */
static int	needs_flood(char c)
{
	return (c == '0' || is_player_char(c));
}

static int	handle_flood_error(int **visited, int rows)
{
	free_visited(visited, rows);
	print_error("Error\nMap not enclosed by walls");
	return (0);
}

static int	scan_row(t_flood *f, int r)
{
	int	c;
	int	len;

	c = 0;
	len = ft_strlen(f->grid[r]);
	while (c < len)
	{
		if (needs_flood(f->grid[r][c]) && !f->visited[r][c])
		{
			if (flood_check(f, r, c))
				return (0);
		}
		c++;
	}
	return (1);
}

int	check_map_closed(t_game *game)
{
	t_flood	f;
	int		r;

	f.visited = alloc_visited(game->map.rows, game->map.cols);
	if (!f.visited)
		return (0);
	f.grid = game->map.grid;
	f.rows = game->map.rows;
	r = 0;
	while (r < game->map.rows)
	{
		if (!scan_row(&f, r))
			return (handle_flood_error(f.visited, game->map.rows));
		r++;
	}
	free_visited(f.visited, game->map.rows);
	return (1);
}
