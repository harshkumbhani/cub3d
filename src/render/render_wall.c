/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:28:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/12 14:02:35 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
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

void	draw_wall(t_mlx *mlx, int top_px, int bottom_px, double wall_h)
{
	double	x_o;
	double	y_o;
	int		position;
	double	factor;

	x_o = 0.0;
	y_o = 0.0;
	position = 0;
	factor = (double)mlx->wall->height / wall_h;
	if (mlx->raycaster->orientation == HORIZONTAL)
		x_o = fmod((mlx->raycaster->horizontal[0] * (mlx->wall->width / BLOCK_SIZE)), mlx->wall->width);
	else
		x_o = fmod((mlx->raycaster->vertical[1] * (mlx->wall->width / BLOCK_SIZE)), mlx->wall->width);
	y_o = (top_px - (HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (top_px < bottom_px)
	{
		position = (int)y_o * mlx->wall->width + (int)x_o;
		put_pixel(mlx, mlx->raycaster->ray, top_px, extract_color(&mlx->wall->pixels[position * 4]));
		y_o += factor;
		top_px++;
	}
}

void	draw_floor_ceiling(t_mlx *mlx, int ray, int top_px, int bottom_px)
{
	int	i;

	i = 0;
	i = bottom_px;
	while (i < HEIGHT)
		put_pixel(mlx, ray, i++, 0xC19A6BFF); // floor 0xC19A6BFF
	i = 0;
	while (i < top_px)
		put_pixel(mlx, ray, i++, 0xF5F5DCFF);
}

void	render_wall(t_mlx *mlx, int ray)
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
