#include "cub3d.h"

//static void	calculate_line_endpoint(t_line *line);
//static void	draw_line(t_line *line);

//void	render_line(t_line *line, int x1, int y1)
//{
//	render_background(*line->line_window);
//	line->x1 = x1;
//	line->y1 = y1;
//	calculate_line_endpoint(line);
//	draw_line(line);
//}

//static void	calculate_line_endpoint(t_line *line)
//{
//	if (line->y1 < 0)
//		line->y1 = 0;
//	else if (line->y1 > HEIGHT)
//		line->y1 = HEIGHT;
//	if (line->x1 < 0)
//		line->x1 = 0;
//	else if (line->x1 > WIDTH)
//		line->x1 = WIDTH;
//	line->dx = abs(line->x1 - line->x0);
//	line->dy = -abs(line->y1 - line->y0);
//	if (line->x0 < line->x1)
//		line->sx = 1;
//	else
//		line->sx = -1;
//	if (line->y0 < line->y1)
//		line->sy = 1;
//	else
//		line->sy = -1;
//}

//static void	draw_line(t_line *line)
//{
//	int	err;
//	int	e2;
//	int	temp[2];

//	temp[0] = line->x0;
//	temp[1] = line->y0;
//	err = line->dx + line->dy;
//	while (true)
//	{
//		mlx_put_pixel(*line->line_window, temp[0], temp[1], 0xFFCC33FF);
//		if (temp[0] == line->x1 && temp[1] == line->y1)
//			break ;
//		e2 = 2 * err;
//		if (e2 >= line->dy)
//		{
//			err += line->dy;
//			temp[0] += line->sx;
//		}
//		if (e2 <= line->dx)
//		{
//			err += line->dx;
//			temp[1] += line->sy;
//		}
//	}
//	mlx_put_pixel(*line->line_window, line->x1, line->y1, 0xFFCC33FF);
//}

// 0xFFCC33FF