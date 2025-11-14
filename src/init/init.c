#include "cub.h"

int	init_display(t_display *display)
{
	if (ini_library(display))
		return (1);
	ini_win(display);
	// display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->bpp = 0;
	display->line_len = 0;
	display->endian = 0;
	return (0);
}

int	init_player(t_player *player)
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
	return (0);//return 1 when dynamic if error
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
	color->r = -1;
	color->g = -1;
	color->b = -1;
	color->hex = (color->r << 16) | (color->g << 8) | color->b;
}

int	init_game(t_game *game)//I changed init_init to init_game
{
	if (init_display(&game->display))
		return (1);
	if (init_map(&game->map))
		return (1);
	init_player(&game->player);
	init_texture(&game->texture);
	init_color(&game->floor);
	init_color(&game->ceiling);
	return (0);
}
