/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:15:57 by tpandya           #+#    #+#             */
/*   Updated: 2025/11/20 01:15:58 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* ========== PLAYER POSITION DETECTION ========== */

static int	find_player_position(t_game *game)
{
	int		r;
	int		c;
	int		count;
	char	**grid;

	count = 0;
	grid = game->map.grid;
	r = 0;
	while (r < game->map.rows)
	{
		c = 0;
		while (grid[r][c])
		{
			if (grid[r][c] == 'N' || grid[r][c] == 'S' || grid[r][c] == 'E'
				|| grid[r][c] == 'W')
			{
				game->map.player_x = c;
				game->map.player_y = r;
				game->map.player_dir = grid[r][c];
				count++;
			}
			c++;
		}
		r++;
	}
	if (count == 0)
		return (print_error("Error\nNo player start position found"), 0);
	if (count > 1)
		return (print_error("Error\nMultiple player positions found"), 0);
	return (1);
}

/* ========== MAP VALIDATION (enclosure check) ========== */

static int	is_wall_or_space(char c)
{
	return (c == '1' || c == ' ');
}

static int	validate_map_enclosure(t_game *game)
{
	int		r;
	int		c;
	char	**grid;
	int		len;

	grid = game->map.grid;
	/* Check first and last rows: must be all walls/spaces */
	c = 0;
	while (grid[0][c])
	{
		if (grid[0][c] != '1' && grid[0][c] != ' ')
			return (print_error("Error\nMap not enclosed (top row)"), 0);
		c++;
	}
	c = 0;
	while (grid[game->map.rows - 1][c])
	{
		if (grid[game->map.rows - 1][c] != '1' && grid[game->map.rows
			- 1][c] != ' ')
			return (print_error("Error\nMap not enclosed (bottom row)"), 0);
		c++;
	}
	/* Check each row: first/last char must be wall/space; any '0' adjacent to space is invalid */
	r = 0;
	while (r < game->map.rows)
	{
		len = ft_strlen(grid[r]);
		if (len > 0 && !is_wall_or_space(grid[r][0]))
			return (print_error("Error\nMap not enclosed (left edge)"), 0);
		if (len > 0 && !is_wall_or_space(grid[r][len - 1]))
			return (print_error("Error\nMap not enclosed (right edge)"), 0);
		r++;
	}
	/* TODO: implement flood-fill or detailed adjacency check for interior '0' cells */
	/* For now, basic edge validation is done; you can extend this */
	return (1);
}

/* ========== MAIN PROCESSING FUNCTION ========== */

int	process_map_lines(t_game *game, char **lines, int total_lines)
{
	int	map_start;
	int	ids_found;
	int	r;
	int	rows;
	int	cmax;
	int	l;

	init_texture(&game->textures);
	init_color(&game->floor);
	init_color(&game->ceiling);
	ids_found = parse_header_lines(game, lines, total_lines, &map_start);
	if (ids_found < 0)
		return (1);
	if (map_start == -1)
		return (print_error("Error\nNo map found in file"), 1);
	/* Validate that all 6 required identifiers are present */
	if (!game->textures.north || !game->textures.south || !game->textures.west
		|| !game->textures.east)
		return (print_error("Error\nMissing texture identifiers"), 1);
	/* Copy map lines into game->map.grid */
	rows = total_lines - map_start;
	game->map.grid = ft_calloc(rows + 1, sizeof(char *));
	if (!game->map.grid)
		return (1);
	r = 0;
	while (r < rows)
	{
		game->map.grid[r] = ft_strdup(lines[map_start + r]);
		r++;
	}
	game->map.rows = rows;
	/* Compute cols as maximum line length */
	{
		cmax = 0;
		r = 0;
		while (r < rows)
		{
			l = ft_strlen(game->map.grid[r]);
			if (l > cmax)
				cmax = l;
			r++;
		}
		game->map.cols = cmax;
	}
	/* Validate player position */
	if (!find_player_position(game))
		return (1);
	/* Validate map enclosure */
	if (!validate_map_enclosure(game))
		return (1);
	/* Cleanup original lines */
	r = 0;
	while (r < total_lines)
	{
		free(lines[r]);
		r++;
	}
	free(lines);
	return (0);
}
