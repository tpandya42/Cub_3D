#ifndef STRUCT_H
# define STRUCT_H

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define TILE_SIZE 6 //minimap BONUS
# define ALL_IDS (ID_NO|ID_SO|ID_WE|ID_EA|ID_F|ID_C)


#include "cub.h"



// DEFINING ENUMS
typedef enum	e_ids
{
	ID_NO = 1 << 0,
	ID_SO = 1 << 1,
	ID_WE = 1 << 2,
	ID_EA = 1 << 3,
	ID_F = 1 << 4,
	ID_C = 1 << 5
}	t_ids;




// DEFINING STRUCTS
typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int	player_x;
	int	player_y;
	char	player_dir;
}	t_map;

typedef struct s_color
{
	int	floor[3];
	int	ceiling[3];
}	t_color;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		width;
	int		height;
}	t_texture;

typedef struct s_player
{
	double  ini_x;       //initial position
    double  ini_y;       //initial position
    double	x;           //update when move
	double	y;           //update when move
	double	dir_x;      //vision
	double	dir_y;      //vision
	double	plane_x;    //widht vission -> ray casting
	double	plane_y;    //widht vission -> ray casting
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_display
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;      //color related
	int		bpp;       //color related
	int		line_len;   //color related
	int		endian;     //color related
}	t_display;

typedef struct s_game //check if can be useful
{
	t_display	display;
	t_map		map;
	t_player	player;
	t_texture	textures;
	t_color		floor;
	t_color		ceiling;
	int		flags;
}	t_game;

#endif
