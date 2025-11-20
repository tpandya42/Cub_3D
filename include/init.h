#ifndef INIT_H	
# define INIT_H

# include "cub.h"

int		init_display(t_display *display);
void	init_player(t_player *player);
void	init_map(t_map *map);
void	init_texture(t_texture *texture);
void	init_color(t_color *color);
void	init_struct(t_game *game);

#endif
