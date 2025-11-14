
# include "cub.h"

int    ini_library(t_display *display)
{
    display->mlx = mlx_init();
	if (!display->mlx)
	{
		print_error("Error: Unable to initialize mlx");
		return (1);
	}
    return (0);
}

int	init_map(t_map *map)
{
	map->grid = NULL;
	map->rows = 0;
	map->cols = 0;
	return (0);//return 1 when dynamic if error
}
