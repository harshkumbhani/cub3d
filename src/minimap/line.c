/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:02:13 by harsh             #+#    #+#             */
/*   Updated: 2024/03/13 15:36:27 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_line_endpoint(t_line *line);
static void	draw_line(t_cub3d *mlx);

void	render_line(t_cub3d *mlx, int x1, int y1)
{
	if (x1 > 350)
		x1 = 349;
	if (y1 > 250)
		y1 = 249;
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	mlx->line->x1 = x1;
	mlx->line->y1 = y1;
	calculate_line_endpoint(mlx->line);
	draw_line(mlx);
}

static void	calculate_line_endpoint(t_line *line)
{
	if (line->y1 < 0)
		line->y1 = 0;
	else if (line->y1 > 250)
		line->y1 = 250;
	if (line->x1 < 0)
		line->x1 = 0;
	else if (line->x1 > 350)
		line->x1 = 350;
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

static void	draw_line(t_cub3d *mlx)
{
	int	err;
	int	e2;
	int	temp[2];

	temp[0] = mlx->line->x0;
	temp[1] = mlx->line->y0;
	err = mlx->line->dx + mlx->line->dy;
	while (true)
	{
		mlx_put_pixel(mlx->player_window, temp[0], temp[1], 0xFFCC33FF);
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
	mlx_put_pixel(mlx->player_window, mlx->line->x1, mlx->line->y1, 0xFFCC33FF);
}

// 0xFFCC33FF