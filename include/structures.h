#ifndef STRUCTURES_H
#define STRUCTURES_H

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////INCLUDES//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "cub3d.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////GLOBAL/STRUCTS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct s_color;
struct s_texture;
struct	s_input;
struct	s_indicator;
struct s_directions;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////DEFINES//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////PARSING///////////////////////////////////
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
	floor	=	0,
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

typedef enum e_map_content
{
	zero	=	0,
	wall	=	1,
	player	=	2,
	space	=	3,
}	t_map_content;

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
	t_map_content		**map;
	struct s_color		*color[2];
	struct s_directions	*directions;
	mlx_image_t			image[4];
	mlx_image_t			*direction_img[4];
}	t_game;
typedef struct s_input
{
	struct s_directions	*texture;
	struct s_color		*floor;
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
	char				*door;
}	t_directions;

typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
}	t_color;

#endif
