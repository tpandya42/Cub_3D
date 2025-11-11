#ifndef STRUCT_H
# define STRUCT_H

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define TILE_SIZE 6 //minimap BONUS

#include "cub.h"

// DEFINE STRUCTS
typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_color//not sure if we do need this
{
	int		r;
	int		g;
	int		b;
	int		hex;	// computed as (r << 16 | g << 8 | b)
}	t_color;

typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
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
}	t_game;

#endif
