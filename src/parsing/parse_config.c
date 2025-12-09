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

/* ========== MAIN PROCESSING FUNCTION ========== */

static int	get_max_width(char **lines, int map_start, int rows)
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

static char	*create_padded_line(const char *src, int width)
{
	char	*line;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	if (src_len > 0 && src[src_len - 1] == '\n')
		src_len--;
	line = malloc(width + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < src_len && i < width)
	{
		line[i] = src[i];
		i++;
	}
	while (i < width)
	{
		line[i] = ' ';
		i++;
	}
	line[width] = '\0';
	return (line);
}

static int	copy_map_grid(t_game *game, char **lines, int map_start, int rows)
{
	int	r;
	int	width;

	width = get_max_width(lines, map_start, rows);
	game->map.grid = ft_calloc(rows + 1, sizeof(char *));
	if (!game->map.grid)
		return (0);
	r = 0;
	while (r < rows)
	{
		game->map.grid[r] = create_padded_line(lines[map_start + r], width);
		if (!game->map.grid[r])
			return (0);
		r++;
	}
	game->map.rows = rows;
	game->map.cols = width;
	return (1);
}

static int	run_validations(t_game *game)
{
	if (!validate_textures(game))
		return (0);
	if (!validate_map_chars(game))
		return (0);
	if (!find_player_position(game))
		return (0);
	if (!validate_player_not_on_edge(game))
		return (0);
	if (!validate_map_closed(game))
		return (0);
	return (1);
}

int	process_map_lines(t_game *game, char **lines, int total_lines)
{
	int	map_start;
	int	ids_found;
	int	rows;

	init_texture(&game->texture);
	init_color(&game->floor);
	init_color(&game->ceiling);
	ids_found = parse_header_lines(game, lines, total_lines, &map_start);
	if (ids_found < 0)
		return (1);
	if (map_start == -1)
		return (print_error("Error\nNo map found in file"), 1);
	if (!game->texture.north || !game->texture.south || !game->texture.west
		|| !game->texture.east)
		return (print_error("Error\nMissing texture identifiers"), 1);
	rows = total_lines - map_start;
	if (rows < 3)
		return (print_error("Error\nMap is too small"), 1);
	if (!copy_map_grid(game, lines, map_start, rows))
		return (print_error("Error\nMemory allocation failed"), 1);
	if (!run_validations(game))
		return (1);
	return (0);
}
