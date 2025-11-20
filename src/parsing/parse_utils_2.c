/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:16:04 by tpandya           #+#    #+#             */
/*   Updated: 2025/11/20 01:16:05 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_rgb(const char *str, int rgb[3])
{
	char	**parts;
	int		i;

	parts = ft_split((char *)str, ',');
	if (!parts)
		return (0);
	i = 0;
	while (parts[i] && i < 3)
		i++;
	if (i != 3)
	{
		while (--i >= 0)
			free(parts[i]);
		free(parts);
		print_error("Error\nRGB format must be R,G,B");
		return (0);
	}
	rgb[0] = ft_atoi(parts[0]);
	rgb[1] = ft_atoi(parts[1]);
	rgb[2] = ft_atoi(parts[2]);
	i = 0;
	while (i < 3)
		free(parts[i++]);
	free(parts);
	return (validate_rgb(rgb[0], rgb[1], rgb[2]));
}

int	parse_color_line(t_game *game, const char *line)
{
	const char	*p;
	int			*dest;
	static int	f_set;
	static int	c_set;

	p = line;
	skip_whitespace(&p);
	dest = NULL;
	if (starts_with(p, "F "))
	{
		if (f_set++)
			return (print_error("Error\nDuplicate floor color"), -1);
		dest = game->floor.floor;
		p += 2;
	}
	else if (starts_with(p, "C "))
	{
		if (c_set++)
			return (print_error("Error\nDuplicate ceiling color"), -1);
		dest = game->ceiling.ceiling;
		p += 2;
	}
	else
		return (0);
	skip_whitespace(&p);
	if (!parse_rgb(p, dest))
		return (-1);
	return (1);
}

/* ========== MAP CHARACTER VALIDATION ========== */

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

int	is_map_line(const char *s)
{
	if (!s || is_blank_line(s))
		return (0);
	while (*s)
	{
		if (!is_map_char(*s))
			return (0);
		s++;
	}
	return (1);
}

/* ========== HEADER LINES PARSING ========== */

int	parse_header_lines(t_game *game, char **lines, int total, int *map_start)
{
	int	i;
	int	res;
	int	ids_found;

	i = 0;
	ids_found = 0;
	while (i < total)
	{
		if (is_blank_line(lines[i]))
		{
			i++;
			continue ;
		}
		if (is_map_line(lines[i]))
		{
			*map_start = i;
			return (ids_found);
		}
		res = parse_texture_line(game, lines[i]);
		if (res == -1)
			return (-1);
		if (res == 0)
			res = parse_color_line(game, lines[i]);
		if (res == -1)
			return (-1);
		if (res == 1)
			ids_found++;
		else if (res == 0)
		{
			print_error("Error\nInvalid configuration line");
			return (-1);
		}
		i++;
	}
	*map_start = -1;
	return (ids_found);
}
