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

static int	grid_cp(t_game *game, char **lines, int map_start, int rows)
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

static int	all_tests(t_game *game)
{
	if (!check_tex(game))
		return (0);
	if (!check_chars(game))
		return (0);
	if (!find_player_position(game))
		return (0);
	if (!check_player_not_on_edge(game))
		return (0);
	if (!check_map_closed(game))
		return (0);
	return (1);
}

static int	check_identifiers(t_game *game)
{
	if (!game->texture.north || !game->texture.south
		|| !game->texture.west || !game->texture.east)
		return (print_error("Error: Missing texture identifiers"), 1);
	if (!(game->flags & ID_F))
		return (print_error("Error: Missing floor color"), 1);
	if (!(game->flags & ID_C))
		return (print_error("Error: Missing ceiling color"), 1);
	return (0);
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
		return (print_error("Error: No map found in file"), 1);
	if (check_identifiers(game) == 1)
		return (1);
	rows = total_lines - map_start;
	if (rows < 3)
		return (print_error("Error: Map is too small"), 1);
	if (!grid_cp(game, lines, map_start, rows))
		return (print_error("Error: Memory allocation failed"), 1);
	if (!all_tests(game))
		return (1);
	return (0);
}
