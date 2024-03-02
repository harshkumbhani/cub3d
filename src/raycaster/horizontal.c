/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:23:30 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/02 01:03:14 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_intersection(double angle, double *h_y)
{
	if (angle > 0 && angle < M_PI)
	{
		*h_y += BLOCK_SIZE;
		return (-1);
	}
	return (1);
}

static int	check_quadrant(double angle)
{
	if (angle > M_PI_2 && angle < (3 * M_PI_2))
		return (true);
	return (false);
}

double	horizontal_inter(t_mlx *mlx, double angle)
{
	int		pixel_check;
	double	h_x;
	double	h_y;

	pixel_check = 0;
	h_x = 0;
	h_y = 0;
	mlx->raycaster->y_step = BLOCK_SIZE;
	mlx->raycaster->x_step = BLOCK_SIZE / tan(angle);
	h_y = floor(mlx->player->y_px / BLOCK_SIZE) * BLOCK_SIZE;
	pixel_check = check_intersection(angle, &h_y);
	h_x = mlx->player->x_px + (h_y - mlx->player->y_px) / tan(angle);
	if ((check_quadrant(angle) == true && mlx->raycaster->x_step > 0)
		|| (check_quadrant(angle) == false && mlx->raycaster->x_step < 0))
		mlx->raycaster->x_step *= -1;
	while (check_wall(mlx, h_x, h_y - pixel_check) == true)
	{
		h_x += mlx->raycaster->x_step;
		h_y += mlx->raycaster->y_step * ((-1) * pixel_check);
	}
	mlx->raycaster->horizontal[0] = h_x;
	mlx->raycaster->horizontal[1] = h_y;
	return (pythagores(h_x, h_y, mlx->player));
}
