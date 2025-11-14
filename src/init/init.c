#include "cub.h"

void	init_display(t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->bpp = 0;
	display->line_len = 0;
	display->endian = 0;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->player_dir = NULL;
}

void	init_player(t_player *player)
{
	player->ini_x = 0;
	player->ini_y = 0;
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->rot_speed = 0;
	player->move_speed = 0;
}

void	init_texture(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->width = 0;
	texture->height = 0;
}

void	init_color(t_color *color)
{
	color->floor = {0};
	color->ceiling = {0};
}

void	init_init(t_game *game)
{
	init_display(&game->display);
	init_map(&game->map);
	init_player(&game->player);
	init_texture(&game->texture);
	init_color(&game->floor);
	init_color(&game->ceiling);
	game->flags = 0;
}
