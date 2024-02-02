#ifndef STRUCTURES_H
#define STRUCTURES_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////GLOBAL/STRUCTS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct s_color;
struct s_texture;
struct	s_input;
struct	s_indicator;

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

typedef enum e_color_typs
{
	red = 0,
	green = 1,
	blue = 2
}	t_color_types;

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
	struct s_color		*color[2];
	struct s_input		*input;
	struct s_indicator	*indicator;
	int					error_occurred;
	int					player_found;
	int					fd;
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

typedef struct	s_indicator
{
	int					texture[4];
	int					color[2];
	int					map[3];
}	t_indicator;
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
