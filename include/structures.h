#ifndef STRUCTURES_H
#define STRUCTURES_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////GLOBAL/STRUCTS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct s_color;
struct s_texture;
struct	s_input;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////DEFINES//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////PARSING///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

typedef enum e_textures
{
	north = 0,
	south = 1,
	east = 2,
	west = 3
}	t_textures;

typedef enum e_colors
{
	red = 0,
	green = 1,
	blue = 2
}	t_colors;

typedef enum e_colors_indicators
{
	floor = 0,
	ceiling = 1
}	t_colors_indicators;

typedef enum e_map_parsing
{
	start = 0,
	end = 1,
	player = 2
}	t_map_parsing;

typedef struct	s_parsing
{
	//struct s_color		*color[2];
	struct s_input		*input;
	int					texture_indicator[4];
	int					color_indicator[2];
	int					color[2][3];
	int					map_indicator[3];
	int					player_found;
	int					error_occurred;
	int					fd;
	char				*texture_path[4];
	char				*line;
}	t_parsing;

typedef struct	s_input
{
	struct s_directions	*texture;
	struct s_color		*floor;
	struct s_color		*ceiling;
	char				**map;
	int					ac;
	char				**av;
}	t_input;

typedef struct	s_directions
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
}	t_directions;

typedef struct	s_color
{
	int					red;
	int					green;
	int					blue;
}	t_color;

#endif
