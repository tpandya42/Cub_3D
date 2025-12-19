/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:34:32 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/19 08:34:35 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_color_format(const char *str)
{
	int	comma_count;
	int	i;

	comma_count = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ',')
		{
			comma_count++;
			if (!ft_isdigit(str[i + 1]) && str[i + 1] != ' ')
				return (0);
		}
		i++;
	}
	if (comma_count != 2)
		return (0);
	return (1);
}

static int	validate_color_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' '
			&& str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_rgb_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	if (i != 3)
	{
		print_error("Error\nRGB format must be R,G,B");
		return (0);
	}
	return (1);
}

static void	fill_rgb(char **parts, int rgb[3])
{
	rgb[0] = ft_atoi(parts[0]);
	rgb[1] = ft_atoi(parts[1]);
	rgb[2] = ft_atoi(parts[2]);
}

int	parse_rgb(const char *str, int rgb[3])
{
	char	**parts;

	if (!check_color_format(str))
		return (print_error("Error\nInvalid color format (need R,G,B)"), 0);
	if (!validate_color_digits(str))
		return (print_error("Error\nColor must contain only digits"), 0);
	parts = ft_split((char *)str, ',');
	if (!parts)
		return (0);
	if (!validate_rgb_parts(parts))
	{
		free_parts(parts);
		return (0);
	}
	fill_rgb(parts, rgb);
	free_parts(parts);
	return (validate_rgb(rgb[0], rgb[1], rgb[2]));
}
