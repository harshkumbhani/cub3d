/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:03:35 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/24 15:22:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init(t_mlx *data)
{
	data->line->pa = &data->player->pa;
	int map[10][13] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
			data->map[i][j] = map[i][j];
	}
	data->player->x_map = 2;
	data->player->y_map = 2;
	data->player->x_px = data->player->x_map * BLOCK_SIZE + BLOCK_SIZE / 2;
	data->player->y_px = data->player->y_map * BLOCK_SIZE + BLOCK_SIZE / 2;
	data->player->fov = (FOV * M_PI) / 180;
	data->player->pa = 0;
	return (EXIT_SUCCESS);
}
