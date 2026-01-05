/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:16 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:36:17 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* ========== FLOOD FILL HELPERS ========== */

void	free_visited(int **visited, int rows)
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

int	**alloc_visited(int rows, int cols)
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
