/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:42:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/02 01:01:40 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda(t_mlx *mlx);

void	raycaster(t_mlx *mlx)
{
	mlx->raycaster->ray = -1;
	mlx->raycaster->ray_angle = mlx->player->pa - (mlx->player->fov / 2);
	while (mlx->raycaster->ray++ < WIDTH)
	{
		dda(mlx);
		render_wall(mlx, mlx->raycaster->ray);
	}
}

static void	dda(t_mlx *mlx)
{
	mlx->raycaster->ray_angle = normalise_angle(mlx->raycaster->ray_angle);
	mlx->raycaster->orientation = HORIZONTAL;
	mlx->raycaster->inter[0] = horizontal_inter(mlx,
			normalise_angle(mlx->raycaster->ray_angle));
	mlx->raycaster->inter[1] = vertical_inter(mlx,
			normalise_angle(mlx->raycaster->ray_angle));
	if (mlx->raycaster->inter[0] <= mlx->raycaster->inter[1])
	{
		//render_line(mlx, mlx->raycaster->end_points[0],
		//	mlx->raycaster->end_points[1]);
		mlx->raycaster->distance_to_wall = mlx->raycaster->inter[0];
	}
	else
	{
		//render_line(mlx, mlx->raycaster->end_points[2],
		//	mlx->raycaster->end_points[3]);
		mlx->raycaster->orientation = VERTICAL;
		mlx->raycaster->distance_to_wall = mlx->raycaster->inter[1];
	}
	mlx->raycaster->ray_angle += (mlx->player->fov / WIDTH);
}
