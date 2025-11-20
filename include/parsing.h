#ifndef PARSING_H
# define PARSING_H

# include "cub.h"

/* ========== FILE READING ========== */
char	**read_all(const char *path, int *total_lines);

/* ========== MAIN PARSING ========== */
int		parse_map(t_game *game, char *path);
int		process_map_lines(t_game *game, char **lines, int total_lines);

/* ========== UTILITY FUNCTIONS (parse_utils.c) ========== */
int		is_blank_line(const char *s);
void	skip_whitespace(const char **p);
int		starts_with(const char *s, const char *prefix);
int		parse_texture_line(t_game *game, const char *line);
int		validate_rgb(int r, int g, int b);

/* ========== COLOR & MAP PARSING (parse_utils_2.c) ========== */
int		parse_rgb(const char *str, int rgb[3]);
int		parse_color_line(t_game *game, const char *line);
int		is_map_char(char c);
int		is_map_line(const char *s);
int		parse_header_lines(t_game *game, char **lines, int total, int *map_start);

#endif
