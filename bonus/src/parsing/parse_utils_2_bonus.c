/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:35:05 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:35:06 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_and_store(t_game *game,
			const char **p, int **dest)
{
	if (starts_with(*p, "F "))
	{
		if (game->flags & ID_F)
			return (print_error("Error: Duplicate floor color"), -1);
		game->flags |= ID_F;
		*dest = game->floor.floor;
		*p += 2;
		return (1);
	}
	if (starts_with(*p, "C "))
	{
		if (game->flags & ID_C)
			return (print_error("Error: Duplicate ceiling color"), -1);
		game->flags |= ID_C;
		*dest = game->ceiling.ceiling;
		*p += 2;
		return (1);
	}
	return (0);
}

int	parse_color_line(t_game *game, const char *line)
{
	const char	*p;
	int			*dest;
	int			status;

	p = line;
	skip_whitespace(&p);
	dest = NULL;
	status = check_and_store(game, &p, &dest);
	if (status <= 0)
		return (status);
	skip_whitespace(&p);
	if (!parse_rgb(p, dest))
		return (-1);
	return (1);
}

/* ========== HEADER LINES PARSING ========== */
static int	parse_config_line(t_game *game, char *line)
{
	int	res;

	res = parse_texture_line(game, line);
	if (res == -1)
		return (-1);
	if (res == 0)
		res = parse_color_line(game, line);
	if (res == -1)
		return (-1);
	if (res == 1)
		return (1);
	print_error("Error: Invalid configuration line");
	return (-1);
}

static int	skip_blanks(char **lines, int *i)
{
	while (lines[*i] && is_blank_line(lines[*i]))
		(*i)++;
	return (1);
}

int	parse_header_lines(t_game *game, char **lines, int total, int *map_start)
{
	int	i;
	int	ids_found;
	int	res;

	i = 0;
	ids_found = 0;
	while (i < total)
	{
		skip_blanks(lines, &i);
		if (i >= total)
			break ;
		if (is_map_line(lines[i]))
		{
			*map_start = i;
			return (ids_found);
		}
		res = parse_config_line(game, lines[i]);
		if (res == -1)
			return (-1);
		ids_found += res;
		i++;
	}
	*map_start = -1;
	return (ids_found);
}
