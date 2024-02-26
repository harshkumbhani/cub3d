#include "cub3d.h"

static void	calculate_line_endpoint(t_line *line);
static void	draw_line(t_mlx *mlx);

void	render_line(t_mlx *mlx, int x1, int y1)
{
	//printf("x1: %d y1: %d\n", x1, y1);
	if (x1 > INT_MAX)
		x1 = INT_MAX;
	if (y1 > INT_MAX)
		y1 = INT_MAX;
	if (x1 < INT_MIN)
		x1 = INT_MIN;
	if (y1 < INT_MIN)
		y1 = INT_MIN;
	mlx->line->x1 = x1;
	mlx->line->y1 = y1;
	calculate_line_endpoint(mlx->line);
	draw_line(mlx);
}

static void	calculate_line_endpoint(t_line *line)
{
	if (line->y1 < 0)
		line->y1 = 0;
	else if (line->y1 > HEIGHT)
		line->y1 = HEIGHT;
	if (line->x1 < 0)
		line->x1 = 0;
	else if (line->x1 > WIDTH)
		line->x1 = WIDTH;
	line->dx = abs(line->x1 - line->x0);
	line->dy = -abs(line->y1 - line->y0);
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
}

static void	draw_line(t_mlx *mlx)
{
	int	err;
	int	e2;
	int	temp[2];

	temp[0] = mlx->line->x0;
	temp[1] = mlx->line->y0;
	err = mlx->line->dx + mlx->line->dy;
	while (true)
	{
		mlx_put_pixel(mlx->line_window, temp[0], temp[1], 0xFFCC33FF);
		if (temp[0] == mlx->line->x1 && temp[1] == mlx->line->y1)
			break ;
		e2 = 2 * err;
		if (e2 >= mlx->line->dy)
		{
			err += mlx->line->dy;
			temp[0] += mlx->line->sx;
		}
		if (e2 <= mlx->line->dx)
		{
			err += mlx->line->dx;
			temp[1] += mlx->line->sy;
		}
	}
	mlx_put_pixel(mlx->line_window, mlx->line->x1, mlx->line->y1, 0xFFCC33FF);
}

// 0xFFCC33FF