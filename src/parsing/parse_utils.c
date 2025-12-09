/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:16:34 by tpandya           #+#    #+#             */
/*   Updated: 2025/11/20 01:16:35 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_blank_line(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	skip_whitespace(const char **p)
{
	while (**p == ' ' || **p == '\t')
		(*p)++;
}

int	starts_with(const char *s, const char *prefix)
{
	while (*prefix)
	{
		if (*s++ != *prefix++)
			return (0);
	}
	return (1);
}

int	parse_texture_line(t_game *game, const char *line)
{
	const char	*p;
	char		**dest;

	p = line;
	skip_whitespace(&p);
	dest = NULL;
	if (starts_with(p, "NO "))
		dest = &game->textures.north;
	else if (starts_with(p, "SO "))
		dest = &game->textures.south;
	else if (starts_with(p, "WE "))
		dest = &game->textures.west;
	else if (starts_with(p, "EA "))
		dest = &game->textures.east;
	else
		return (0);
	p += 3;
	skip_whitespace(&p);
	if (*dest)
	{
		print_error("Error\nDuplicate texture identifier");
		return (-1);
	}
	*dest = ft_strdup(p);
	return (1);
}

/* ========== COLOR PARSING ========== */

int	validate_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		print_error("Error\nRGB values must be in range [0,255]");
		return (0);
	}
	return (1);
}
