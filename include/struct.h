/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:51:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/28 15:16:17 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	char	**grid;
	char	*path;
	int		rows;
	int		cols;
	int	total_lines;
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

typedef struct s_ray
{
	double	dirx;
	double	diry;
	int		current_x;
	int		current_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_dist; 
}	t_ray;

typedef struct s_sampler//check
{
	int		tex_x;
	double	tex_pos;
	double	step;
}	t_sampler;

typedef struct s_wall_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width; 
	int		height;
}	t_wall_data;

typedef struct s_render_tex
{
	t_wall_data	north;
	t_wall_data	south;
	t_wall_data	west;
	t_wall_data	east;
}	t_render_tex;


typedef struct s_wall
{
	int			wall_start;
	int			wall_end;
	int			col;
	t_wall_data	*tex;
}	t_wall;

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
	int	tile_size;
	int	width;
	int	height;
	int	offset_x;
	int	offset_y;
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
	t_display		display;
	t_map			map;
	t_player		player;
	t_texture		texture;
	t_render_tex	rtex;
	t_color			floor;
	t_color			ceiling;
	t_minimap		minimap;
	t_input_key		key;
	int				flags;
}	t_game;

#endif