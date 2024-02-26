/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:28:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/26 20:55:17 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx->image, x, y, color);
}

int	get_color(t_raycaster *ray, int flag)
{
	//ray->ray_angle = normalise_angle(ray->ray_angle);
	if (flag == HORIZONTAL)
	{
		if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
			return (0xFF0000FF); // SOUTH WALL RED
		else
			return (0x00FF00FF); // NORTH WALL GREEN
	}
	else
	{
		if (ray->ray_angle > M_PI_2 && ray->ray_angle < 3 * M_PI_2)
			return (0xB5B5B5FF); // WEST WALL GREY
		else
			return (0x0000FFFF); // EAST WALL blue
	}
}

void	draw_wall(t_mlx *mlx, int ray, int top_px, int bottom_px)
{
	int	color;

	color = get_color(mlx->raycaster, mlx->raycaster->orientation);
	while (top_px < bottom_px)
		put_pixel(mlx, ray, top_px++, color);
}

void	draw_floor_ceiling(t_mlx *mlx, int ray, int top_px, int bottom_px)
{
	int	i;

	i = 0;
	i = bottom_px;
	while (i < HEIGHT)
		put_pixel(mlx, ray, i++, 0xB99470FF);
	i = 0;
	while (i < top_px)
		put_pixel(mlx, ray, i++, 0x89CFF3FF);
}

void	render_wall(t_mlx *mlx, int ray)
{
	double	wall_h;
	double	bottom_pixel;
	double	top_pixel;

	mlx->raycaster->distance_to_wall *= cos(normalise_angle(mlx->raycaster->ray_angle - mlx->player->pa));
	wall_h = (BLOCK_SIZE / mlx->raycaster->distance_to_wall) * ((WIDTH / 2) / tan(mlx->player->fov / 2));
	bottom_pixel = (HEIGHT / 2) + (wall_h / 2);
	top_pixel = (HEIGHT / 2) - (wall_h / 2);
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;
	draw_wall(mlx, ray, top_pixel, bottom_pixel);
	draw_floor_ceiling(mlx, ray, top_pixel, bottom_pixel);
}
