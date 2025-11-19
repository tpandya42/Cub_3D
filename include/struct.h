/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:51:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 18:11:25 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIN_WIDTH 1200 //check if all this macros we can move it to defines.h
# define WIN_HEIGHT 800
# define TILE_SIZE 64 //3d
# define ALL_IDS (ID_NO|ID_SO|ID_WE|ID_EA|ID_F|ID_C)

# include "cub.h"



// DEFINING ENUMS
typedef enum e_ids
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
	int		player_x;
	int		player_y;
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

typedef struct s_input_key
{
	int	forward;
	int	back;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
}	t_input_key;

typedef struct s_player
{
	double	ini_x;
	double	ini_y;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_line
{
	int	x0;// starting X coordinate of the line
	int	y0;// starting Y coordinate of the line
	int	x1;// ending X coordinate of the line
	int	y1;// ending Y coordinate of the line
	int	dx;// absolute difference in X (x1 - x0)
	int	dy;// absolute difference in Y (y1 - y0)
	int	sx;// step direction in X (+1 or -1)
	int	sy;// step direction in Y (+1 or -1)
	int	err;//accumulated error term for Bresenham’s line algorithm
}	t_line;

typedef struct s_minimap
{
	int tile_size;		// size of each cell
	int width;			// width in pixels
	int height;			// height in pixels
	int offset_x;		// horizontal offset from the window
	int offset_y;		// vertical offset from the window
}	t_minimap;

typedef struct s_display
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp; 
	int		line_len;
	int		endian;
	int		win_w;
	int		win_h;
}	t_display;

typedef struct s_game
{
	t_display	display;
	t_map		map;
	t_player	player;
	t_texture	textures;
	t_color		floor;
	t_color		ceiling;
	t_minimap	minimap;
	t_input_key	key;
	int			flags;
}	t_game;

#endif
