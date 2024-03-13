#ifndef STRUCTURES_H
#define STRUCTURES_H

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////INCLUDES//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include "cub3d.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////GLOBAL/STRUCTS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct	s_color;
struct	s_texture;
struct	s_input;
struct	s_indicator;
struct	s_directions;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////DEFINES//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

typedef enum e_textures
{
	north	=	0,
	south	=	1,
	east	=	2,
	west	=	3
}	t_textures;

typedef enum e_color_typs
{
	red		=	0,
	green	=	1,
	blue	=	2
}	t_color_types;

typedef enum e_colors_indicators
{
	ground	=	0,
	ceiling	=	1
}	t_colors_indicators;

typedef enum e_map_status
{
	start	=	0,
	end		=	1,
}	t_map_status;

typedef enum e_map_dimensions
{
	width	=	0,
	height	=	1
}	t_map_dimensions;

typedef enum e_coordinates
{
	x		=	0,
	y		=	1
}	t_coordinates;

typedef enum e_map_content
{
	zero	=	0,
	wall	=	1,
	player	=	2,
	space	=	3,
}	t_map_content;

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////PARSING///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

typedef struct s_parsing
{
	struct s_input		*input;
	struct s_indicator	*indicator;
	int					error_occurred;
	int					player_found;
	int					fd;
	char				*line;
}	t_parsing;

typedef struct s_game
{
	int					map_dimensions[2];
	int					player_position[2];
	int					direction_facing;
	t_map_content		**map;
	struct s_color		*color[2];
	struct s_directions	*directions;
	mlx_texture_t		*direction_img[4];
}	t_game;

typedef struct s_input
{
	struct s_directions	*texture;
	struct s_color		*ground;
	struct s_color		*ceiling;
	char				**map;
	int					ac;
	char				**av;
}	t_input;

typedef struct s_indicator
{
	int					texture[4];
	int					color[2];
	int					map[2];
	int					player;
}	t_indicator;

typedef struct s_directions
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
}	t_directions;

typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
}	t_color;

typedef struct s_player
{
	int		x_px;
	int		y_px;
	int		x_map;
	int		y_map;
	double	fov;
	double	pa;
}	t_player;

typedef	struct s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}	t_line;

typedef	struct s_offsets
{
	double	x_offset;
	double	y_offset;
	double	factor;
	int		tex_height;
	int		tex_width;
}	t_offsets;

/// @brief 
/// inter[0] -> horizontal intersection
///	inter[1] -> vertical intersection
typedef	struct s_raycaster
{
	int		ray;
	int		ray_direction;
	int		player_pos[2];
	int		map_pos[2];
	int		orientation;
	double	horizontal[2];
	double	vertical[2];
	double	x_step;
	double	y_step;
	double	inter[2];
	double	ray_angle;
	double	distance_to_wall;
}	t_raycaster;

typedef	struct	s_minimap
{
	int		xpos;
	int		ypos;
	int		player_xpos;
	int		player_ypos;
	double	block_width;
	double	block_height;
}	t_minimap;

typedef	struct s_cub3d
{
	int				map[10][13];
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_image_t		*player_window;
	mlx_image_t		*line_window;
	mlx_image_t		*minimap;
	mlx_texture_t	*wall;
	t_game			*meta_data;
	t_line			*line;
	t_player		*player;
	t_raycaster		*raycaster;
	t_minimap		*hud;
}	t_cub3d;

#endif
