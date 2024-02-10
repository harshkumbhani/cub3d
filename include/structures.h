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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef	struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_line;
typedef	struct s_image
{
	double		angle;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*player;
	mlx_image_t	*window_lin;
	t_line		*line;
}	t_image;

#endif
