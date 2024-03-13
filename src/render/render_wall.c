/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:28:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 03:45:48 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_cub3d *mlx, int top_px, int bottom_px, double wall_h)
{
	double			x_offset;
	double			y_offset;
	double			factor;
	int				position;
	mlx_texture_t	*direction;

	position = 0;
	x_offset = 0.0;
	direction = get_wall_texture(mlx, mlx->raycaster->ray_angle);
	factor = (double)direction->height / wall_h;
	y_offset = (top_px - (HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_offset < 0)
		y_offset = 0.0;
	x_offset = calculate_x_offset(mlx);
	x_offset = fmod(x_offset, BLOCK_SIZE) * (direction->width / BLOCK_SIZE);
	while (top_px < bottom_px)
	{
		position = (int)y_offset * direction->width
			+ (int)x_offset;
		put_pixel(mlx, mlx->raycaster->ray, top_px++,
			extract_color(&direction->pixels[position * 4]));
		y_offset += factor;
	}
}

void	draw_floor_ceiling(t_cub3d *mlx, int ray, int top_px, int bottom_px)
{
	int	i;
	int	color;

	i = 0;
	color = color_function(mlx->meta_data->color[ceiling]->red,
			mlx->meta_data->color[ceiling]->green,
			mlx->meta_data->color[ceiling]->blue, 50);
	while (i < top_px)
		put_pixel(mlx, ray, i++, color);
	i = bottom_px;
	color = color_function(mlx->meta_data->color[ground]->red,
			mlx->meta_data->color[ground]->green,
			mlx->meta_data->color[ground]->blue, 250);
	while (i < HEIGHT)
		put_pixel(mlx, ray, i++, color);
}

void	render_wall(t_cub3d *mlx, int ray)
{
	double	wall_h;
	double	bottom_pixel;
	double	top_pixel;

	mlx->raycaster->distance_to_wall *= cos(normalise_angle(mlx->player->pa
				- mlx->raycaster->ray_angle));
	wall_h = (BLOCK_SIZE / mlx->raycaster->distance_to_wall)
		* ((WIDTH / 2) / tan(mlx->player->fov / 2));
	bottom_pixel = (HEIGHT / 2) + (wall_h / 2);
	top_pixel = (HEIGHT / 2) - (wall_h / 2);
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;
	draw_wall(mlx, top_pixel, bottom_pixel, wall_h);
	draw_floor_ceiling(mlx, ray, top_pixel, bottom_pixel);
}
