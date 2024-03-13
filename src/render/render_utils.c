/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:50:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 03:36:00 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_cub3d *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		mlx_put_pixel(mlx->image, x, y, color);
}

uint32_t	color_function(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

uint32_t	extract_color(uint8_t *pixels)
{
	return ((uint32_t)(*pixels) << 24 | (uint32_t)(*(pixels + 1)) << 16 | \
		(uint32_t)(*(pixels + 2)) << 8 | (uint32_t)(*(pixels + 3)) << 0);
}

mlx_texture_t	*get_wall_texture(t_cub3d *cub3d, double ray_angle)
{
	mlx_texture_t	*return_tex;

	return_tex = NULL;
	ray_angle = normalise_angle(ray_angle);
	if (cub3d->raycaster->orientation == HORIZONTAL)
	{
		if (ray_angle >= 0 && ray_angle <= M_PI)
			return_tex = cub3d->meta_data->direction_img[SOUTH];
		else
			return_tex = cub3d->meta_data->direction_img[NORTH];
	}
	else
	{
		if (ray_angle >= M_PI_2 && ray_angle <= 3 * M_PI_2)
			return_tex = cub3d->meta_data->direction_img[WEST];
		else
			return_tex = cub3d->meta_data->direction_img[EAST];
	}
	return (return_tex);
}

double	calculate_x_offset(t_cub3d *cub3d)
{
	double	x_offset;

	x_offset = 0.0;
	if (cub3d->raycaster->orientation == HORIZONTAL)
	{
		x_offset = cub3d->raycaster->horizontal[0];
		if (normalise_angle(cub3d->raycaster->ray_angle) < M_PI)
			x_offset = BLOCK_SIZE - fmod(x_offset, BLOCK_SIZE) - 1;
		if (x_offset < 0)
			x_offset = 0;
	}
	else
	{
		x_offset = cub3d->raycaster->vertical[1];
		if (normalise_angle(cub3d->raycaster->ray_angle) >= M_PI_2
			&& normalise_angle(cub3d->raycaster->ray_angle) < 3 * M_PI_2)
			x_offset = BLOCK_SIZE - fmod(x_offset, BLOCK_SIZE) - 1;
		if (x_offset < 0)
			x_offset = 0;
	}
	return (x_offset);
}
