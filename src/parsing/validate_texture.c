/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:00:00 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/09 12:00:00 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* Remove trailing newline and whitespace from string */
static void	trim_trailing(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == ' '
			|| str[len - 1] == '\t' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
}

/* Check if file exists and is readable */
static int	check_file_readable(const char *path)
{
	int		fd;
	char	buf[1];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error\nCannot open texture file");
		return (0);
	}
	if (read(fd, buf, 1) < 0)
	{
		close(fd);
		print_error("Error\nCannot read texture file");
		return (0);
	}
	close(fd);
	return (1);
}

/* Check if file has .xpm extension */
static int	check_xpm_extension(const char *path)
{
	const char	*ext;

	ext = ft_strrchr(path, '.');
	if (!ext)
	{
		print_error("Error\nTexture file missing extension");
		return (0);
	}
	if (ft_strcmp(ext, ".xpm") != 0)
	{
		print_error("Error\nTexture file must have .xpm extension");
		return (0);
	}
	return (1);
}

/* Validate a single texture path */
static int	validate_single_texture(char *path)
{
	if (!path)
	{
		print_error("Error\nMissing texture path");
		return (0);
	}
	trim_trailing(path);
	if (!check_xpm_extension(path))
		return (0);
	if (!check_file_readable(path))
		return (0);
	return (1);
}

/* Validate all texture paths exist and are readable .xpm files */
int	validate_textures(t_game *game)
{
	if (!validate_single_texture(game->texture.north))
		return (0);
	if (!validate_single_texture(game->texture.south))
		return (0);
	if (!validate_single_texture(game->texture.west))
		return (0);
	if (!validate_single_texture(game->texture.east))
		return (0);
	return (1);
}
