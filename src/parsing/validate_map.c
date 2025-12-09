/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:00:00 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/09 12:00:00 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* ========== FLOOD FILL HELPERS ========== */

static void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static int	**alloc_visited(int rows, int cols)
{
	int	**visited;
	int	i;

	visited = malloc(rows * sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		visited[i] = ft_calloc(cols + 1, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

/* ========== FLOOD FILL ALGORITHM ========== */

static int	flood_check(char **grid, int **visited, int r, int c, int rows)
{
	int	len;

	if (r < 0 || r >= rows)
		return (1);
	len = ft_strlen(grid[r]);
	if (c < 0 || c >= len)
		return (1);
	if (grid[r][c] == ' ' || grid[r][c] == '\n' || grid[r][c] == '\0')
		return (1);
	if (grid[r][c] == '1' || visited[r][c])
		return (0);
	visited[r][c] = 1;
	if (flood_check(grid, visited, r + 1, c, rows))
		return (1);
	if (flood_check(grid, visited, r - 1, c, rows))
		return (1);
	if (flood_check(grid, visited, r, c + 1, rows))
		return (1);
	if (flood_check(grid, visited, r, c - 1, rows))
		return (1);
	return (0);
}

/* ========== MAP ENCLOSURE VALIDATION ========== */

int	validate_map_closed(t_game *game)
{
	int		**visited;
	int		r;
	int		c;
	int		len;
	char	**grid;

	grid = game->map.grid;
	visited = alloc_visited(game->map.rows, game->map.cols);
	if (!visited)
		return (0);
	r = 0;
	while (r < game->map.rows)
	{
		len = ft_strlen(grid[r]);
		c = 0;
		while (c < len)
		{
			if ((grid[r][c] == '0' || is_player_char(grid[r][c]))
				&& !visited[r][c])
			{
				if (flood_check(grid, visited, r, c, game->map.rows))
				{
					free_visited(visited, game->map.rows);
					return (print_error("Error\nMap not enclosed by walls"), 0);
				}
			}
			c++;
		}
		r++;
	}
	free_visited(visited, game->map.rows);
	return (1);
}

/* ========== MAP CHARACTER VALIDATION ========== */

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == '\n' || c == '\0');
}

int	validate_map_chars(t_game *game)
{
	int		r;
	int		c;
	char	**grid;

	grid = game->map.grid;
	r = 0;
	while (r < game->map.rows)
	{
		c = 0;
		while (grid[r][c])
		{
			if (!is_valid_map_char(grid[r][c]))
			{
				print_error("Error\nInvalid character in map");
				return (0);
			}
			c++;
		}
		r++;
	}
	return (1);
}

/* ========== PLAYER POSITION VALIDATION ========== */

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	validate_player_not_on_edge(t_game *game)
{
	int	px;
	int	py;
	int	len;

	px = game->map.player_x;
	py = game->map.player_y;
	len = ft_strlen(game->map.grid[py]);
	if (py == 0 || py == game->map.rows - 1)
	{
		print_error("Error\nPlayer cannot be on map edge (top/bottom)");
		return (0);
	}
	if (px == 0 || px >= len - 1)
	{
		print_error("Error\nPlayer cannot be on map edge (left/right)");
		return (0);
	}
	return (1);
}
