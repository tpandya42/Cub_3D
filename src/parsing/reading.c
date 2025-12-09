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
char	**read_all(const char *path, int *total_lines)
{
	int		fd;
	char	**grid;
	char	*line;
	int		count;
	char	**tmp;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = NULL;
	count = 0;
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		tmp = malloc(sizeof(*tmp) * (count + 2));
		if (!tmp)
		{
			close(fd);
			return (NULL);
		}
		if (grid)
		{
			ft_memcpy(tmp, grid, sizeof(*tmp) * count);
			free(grid);
		}
		grid = tmp;
		grid[count++] = line;
		grid[count] = NULL;
	}
	close(fd);
	*total_lines = count;
	return (grid);
}
