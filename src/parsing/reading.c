/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:16:15 by tpandya           #+#    #+#             */
/*   Updated: 2025/11/20 01:16:16 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* Read all lines from a file into dynamically allocated array of strings.
 * Each line is stored without the trailing newline.
 * Returns NULL on error, otherwise array of strings terminated by NULL.
 */

static void	clean_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	**grid_grow(char **grid, int count)
{
	char	**temp;

	temp = malloc(sizeof(char *) * (count + 2));
	if (!temp)
		return (NULL);
	if (grid)
	{
		ft_memcpy(temp, grid, sizeof(char *) * count);
		free(grid);
	}
	temp[count + 1] = NULL;
	return (temp);
}

static char	**read_lines(int fd, int *count)
{
	char	*line;
	char	**grid;
	char	**temp;

	grid = NULL;
	*count = 0;
	line = get_next_line(fd);
	while (line)
	{
		clean_newline(line);
		temp = grid_grow(grid, *count);
		if (!temp)
			return (NULL);
		grid = temp;
		grid[*count] = line;
		(*count)++;
		line = get_next_line(fd);
	}
	return (grid);
}

char	**read_all(const char *path, int *total_lines)
{
	char				**grid;
	int					fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = read_lines(fd, total_lines);
	close(fd);
	return (grid);
}
