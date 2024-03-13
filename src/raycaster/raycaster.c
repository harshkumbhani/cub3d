/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:42:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 18:32:10 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda(t_cub3d *cub3d);

void	raycaster(t_cub3d *cub3d)
{
	cub3d->raycaster->ray = -1;
	cub3d->raycaster->ray_angle = cub3d->player->pa - (cub3d->player->fov / 2);
	while (++cub3d->raycaster->ray < WIDTH)
	{
		dda(cub3d);
		render_wall(cub3d, cub3d->raycaster->ray);
	}
}

static void	dda(t_cub3d *mlx)
{
	mlx->raycaster->ray_angle = normalise_angle(mlx->raycaster->ray_angle);
	mlx->raycaster->orientation = HORIZONTAL;
	mlx->raycaster->inter[0] = horizontal_inter(mlx,
			normalise_angle(mlx->raycaster->ray_angle));
	mlx->raycaster->inter[1] = vertical_inter(mlx,
			normalise_angle(mlx->raycaster->ray_angle));
	if (mlx->raycaster->inter[0] <= mlx->raycaster->inter[1])
		mlx->raycaster->distance_to_wall = mlx->raycaster->inter[0];
	else
	{
		mlx->raycaster->orientation = VERTICAL;
		mlx->raycaster->distance_to_wall = mlx->raycaster->inter[1];
	}
	mlx->raycaster->ray_angle += (mlx->player->fov / WIDTH);
}
