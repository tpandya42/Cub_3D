/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:41:30 by tpandya           #+#    #+#             */
/*   Updated: 2025/12/19 08:41:31 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	free_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}
