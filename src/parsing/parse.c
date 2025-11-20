/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:15:52 by tpandya           #+#    #+#             */
/*   Updated: 2025/11/20 01:15:54 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* High-level entry point for parsing:
 * 1. Read all lines from the .cub file
 * 2. Process lines to extract textures, colors, and map
 * 3. Validate all requirements per cub3D spec
 */
int	parse_map(t_game *game, char *path)
{
	char	**lines;
	int		total_lines;

	lines = read_all(path, &total_lines);
	if (!lines)
	{
		print_error("Error\nFailed to read map file");
		return (1);
	}
	if (process_map_lines(game, lines, total_lines))
		return (1);
	return (0);
}
