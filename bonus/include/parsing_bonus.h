/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:27:10 by tpandya           #+#    #+#             */
/*   Updated: 2026/01/05 15:27:12 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "cub.h"

typedef struct s_flood
{
	char	**grid;
	int		**visited;
	int		rows;
}			t_flood;

/* ========== FILE READING ========== */
char		**read_all(const char *path, int *total_lines);

/* ========== MAIN PARSING ========== */
int			parse_map(t_game *game, char *path);
int			find_player_position(t_game *game);
int			get_max_width(char **lines, int map_start, int rows);
int			process_map_lines(t_game *game, char **lines, int total_lines);

/* ========== UTILITY FUNCTIONS (parse_utils.c) ========== */
void		free_visited(int **visited, int rows);
int			**alloc_visited(int rows, int cols);
int			flood_check(t_flood *f, int r, int c);
int			is_valid_map_char(char c);
int			is_player_char(char c);
int			is_blank_line(const char *s);
void		skip_whitespace(const char **p);
int			starts_with(const char *s, const char *prefix);
int			parse_texture_line(t_game *game, const char *line);
int			validate_rgb(int r, int g, int b);
void		free_parts(char **parts);

/* ========== COLOR & MAP PARSING (parse_utils_2.c) ========== */
int			parse_rgb(const char *str, int rgb[3]);
int			parse_color_line(t_game *game, const char *line);
int			is_map_char(char c);
int			is_map_line(const char *s);
int			parse_header_lines(t_game *game, char **lines, int total,
				int *mstart);

/* ========== MAP VALIDATION (validate_map.c) ========== */
int			check_map_closed(t_game *game);
int			check_chars(t_game *game);
int			is_player_char(char c);
int			check_player_not_on_edge(t_game *game);

/* ========== TEXTURE VALIDATION (validate_texture.c) ========== */
int			check_tex(t_game *game);

#endif
