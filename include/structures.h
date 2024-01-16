#ifndef STRUCTURES_H
#define STRUCTURES_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////GLOBAL/STRUCTS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////
struct s_color;
struct s_texture;

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////INPUT/PARSING/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
typedef struct	s_input
{
	struct s_texture	*texture;
	struct s_color		*floor;
	struct s_color		*ceiling;
	char				**map;
}	t_input;

typedef struct	s_texture
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
}	t_texture;

typedef struct	s_color
{
	int					red;
	int					green;
	int					blue;
}	t_color;

#endif