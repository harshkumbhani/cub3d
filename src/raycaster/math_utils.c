/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:21:23 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/24 12:22:41 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	pythagores(double x, double y, t_player *player)
{
	return (sqrt(pow(x - player->x_px, 2) + pow(y - player->y_px, 2)));
}

double	normalise_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

int	check_wall(t_mlx *mlx, double x, double y)
{
	if (x < 0 || y < 0)
		return (false);
	mlx->raycaster->map_pos[0] = floor(x / BLOCK_SIZE);
	mlx->raycaster->map_pos[1] = floor(y / BLOCK_SIZE);
	if (mlx->raycaster->map_pos[0] > 13 || mlx->raycaster->map_pos[1] > 10)
		return (false);
	if (mlx->map[mlx->raycaster->map_pos[1]][mlx->raycaster->map_pos[0]] == 1)
		return (false);
	return (true);
}
