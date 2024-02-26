/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:35 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/26 20:43:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_intersection(double angle, double *v_x)
{
	if (!(angle > M_PI_2 && angle < 3 * M_PI_2))
	{
		*v_x += BLOCK_SIZE;
		return (-1);
	}
	return (1);
}

static int	check_quadrant(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (true);
	return (false);
}

double	vertical_inter(t_mlx *mlx, double angle)
{
	int		pixel_check;
	double	v_x;
	double	v_y;

	pixel_check = 0;
	v_x = 0;
	v_y = 0;
	mlx->raycaster->x_step = BLOCK_SIZE;
	mlx->raycaster->y_step = BLOCK_SIZE * tan(angle);
	v_x = floor(mlx->player->x_px / BLOCK_SIZE) * BLOCK_SIZE;
	pixel_check = check_intersection(angle, &v_x);
	v_y = mlx->player->y_px + ((v_x - mlx->player->x_px) * tan(angle));
	if ((check_quadrant(angle) == false && mlx->raycaster->y_step > 0)
		|| (check_quadrant(angle) == true && mlx->raycaster->y_step < 0))
		mlx->raycaster->y_step *= -1;
	while (check_wall(mlx, v_x - pixel_check, v_y) == true)
	{
		v_x += mlx->raycaster->x_step * ((-1) * pixel_check);
		v_y += mlx->raycaster->y_step;
	}
	mlx->raycaster->end_points[2] = (int)v_x;
	mlx->raycaster->end_points[3] = (int)v_y;
	return (pythagores(v_x, v_y, mlx->player));
}
