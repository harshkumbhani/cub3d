#include "cub3d.h"

static void	calculate_line_endpoint(t_line *line);
static void	draw_line(t_line *line);

void	render_line(t_line *line, int x1, int y1)
{
	render_background(*line->line_window);
	line->x1 = x1;
	line->y1 = y1;
	calculate_line_endpoint(line);
	draw_line(line);
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
	line->dy = abs(line->y1 - line->y0);
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
}

static void	draw_line(t_line *line)
{
	int	param;
	int	x;
	int	y;

	x = line->x0;
	y = line->y0;
		//printf("x1: %d y1: %d\n", line->x1, line->y1);
	param = (2 * line->dy) - line->dx;
	while (x != line->x1 || y != line->y1)
	{
		printf("param: %d\n", param);
		mlx_put_pixel(*line->line_window, x, y, 0xFFCC33FF);
		if (param < 0)
			param += 2 * line->dy;
		else
		{
			y += line->sy;
			param += 2 * (line->dy - line->dx);
		}
		x += line->sx;
	}
	mlx_put_pixel(*line->line_window, line->x1, line->y1, 0xFFCC33FF);
}

// 0xFFCC33FF