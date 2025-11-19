#include "cub.h"
#include "parsing.h"



char	**parser(char **map, t_game *game)
{
			
}

int	parse_map(t_game *game, char *path)
{
	if (read_parse(game, path))
		return (1);
	return (0);
}
