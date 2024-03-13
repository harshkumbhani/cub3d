/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:43:29 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 17:51:02 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	collision_with_wall(t_cub3d *mlx, double x, double y)
{
	int	new_pos_x;
	int	new_pos_y;
	int	map_pos[2];

	new_pos_x = roundf(mlx->player->x_px + x);
	new_pos_y = roundf(mlx->player->y_px + y);
	map_pos[0] = new_pos_x >> 6;
	map_pos[1] = new_pos_y >> 6;
	mlx->player->x_map = map_pos[0];
	mlx->player->y_map = map_pos[1];
	if (mlx->meta_data->map[map_pos[1]][map_pos[0]] != wall &&
		mlx->meta_data->map[map_pos[1]][mlx->player->x_px >> 6] != wall &&
		mlx->meta_data->map[mlx->player->y_px >> 6][map_pos[0]] != wall)
		return (false);
	return (true);
}
