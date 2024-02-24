/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:42:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/24 12:53:38 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster(t_mlx *mlx)
{
	int	orientation;

	orientation = HORIZONTAL;
	mlx->raycaster->ray = 0;
	mlx->raycaster->ray_angle = mlx->player->pa - (mlx->player->fov / 2);
	while (mlx->raycaster->ray < WIDTH)
	{
		mlx->raycaster->inter[0] = horizontal_inter(mlx,
				normalise_angle(mlx->player->pa));
		mlx->raycaster->inter[1] = vertical_inter(mlx,
				normalise_angle(mlx->player->pa));
		if (mlx->raycaster->inter[0] <= mlx->raycaster->inter[1])
			mlx->raycaster->distance_to_wall = mlx->raycaster->inter[0];
		else
		{
			orientation = VERTICAL;
			mlx->raycaster->distance_to_wall = mlx->raycaster->inter[1];
		}
		// render wall;
		mlx->raycaster->ray++;
		mlx->raycaster->ray_angle += (mlx->player->fov / WIDTH);
	}
}
