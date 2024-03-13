/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:03:35 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 03:55:44 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		find_player_position(t_cub3d *data);
static double	get_player_direction(t_cub3d *data);

int	init_data(t_cub3d *data)
{
	find_player_position(data);
	data->player->x_px = data->player->x_map * BLOCK_SIZE + BLOCK_SIZE / 2;
	data->player->y_px = data->player->y_map * BLOCK_SIZE + BLOCK_SIZE / 2;
	data->player->fov = (FOV * M_PI) / 180;
	data->player->pa = get_player_direction(data);
	return (EXIT_SUCCESS);
}

void	find_player_position(t_cub3d *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->meta_data->map_dimensions[height])
	{
		x = -1;
		while (++x < data->meta_data->map_dimensions[width])
		{
			if (data->meta_data->map[y][x] == player)
			{
				data->player->x_map = x;
				data->player->y_map = y;
				break ;
			}
		}
	}
	return ;
}

double	get_player_direction(t_cub3d *data)
{
	double	return_angle;

	(void)data;
	return_angle = 0.0;
	return_angle = 0;
	return (return_angle);
}
