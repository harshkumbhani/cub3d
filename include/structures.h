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
	int		x_px;
	int		y_px;
	int		x_map;
	int		y_map;
	float	fov;
	double	pa;
}	t_player;

typedef	struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	double	*pa;
	void	**line_window;
}	t_line;

typedef	struct s_raycaster
{
	int		x_step;
	int		y_step;
	int		player_pos[2];
	int		intersection[2];
	int		map_pos[2];
	double	ray_a;
	double	distance;
}	t_raycaster;

typedef	struct s_mlx
{
	int			map[10][13];
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*player_window;
	mlx_image_t	*line_window;
	t_line		*line;
	t_player	*player;
	t_raycaster	*raycaster;
}	t_mlx;

#endif
