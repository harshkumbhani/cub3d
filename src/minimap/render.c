/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 19:01:26 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(mlx_image_t *image, int height, int width)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			mlx_put_pixel(image, x, y, 0x000000FF);
	}
}

void	draw_rectangle(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;

	j = cub3d->hud->ypos;
	while (++j < cub3d->hud->ypos + (int)cub3d->hud->block_height)
	{
		i = cub3d->hud->xpos;
		while (++i < cub3d->hud->xpos + (int)cub3d->hud->block_width)
		{
			mlx_put_pixel(cub3d->minimap, i, j, color);
		}
	}
}

void	draw_player(t_cub3d *cub3d, int x, int y, int width)
{
	int	i;
	int	j;

	j = -1;
	while (++j < width)
	{
		i = -1;
		while (++i < width && y > 0 && x > 0)
			mlx_put_pixel(cub3d->player_window, x + i, y + j, 0x00FF00FF);
	}
}

void	render_minimap(t_cub3d *cub3d)
{
	int			i;
	int			j;
	t_minimap	*hud;

	j = -1;
	hud = cub3d->hud;
	hud->block_width = MINIMAP_SIZE_X
		/ ((double)cub3d->meta_data->map_dimensions[width] - 2);
	hud->block_height = MINIMAP_SIZE_Y
		/ (double)cub3d->meta_data->map_dimensions[height];
	render_background(cub3d->player_window, MINIMAP_SIZE_Y, MINIMAP_SIZE_X);
	hud->ypos = 0;
	while (++j < cub3d->meta_data->map_dimensions[height])
	{
		i = 0;
		hud->xpos = 0;
		while (++i < cub3d->meta_data->map_dimensions[width] - 1)
		{
			if (cub3d->meta_data->map[j][i] == wall)
				draw_rectangle(cub3d, 0xFF0000FF);
			hud->xpos += (int)hud->block_width;
		}
		hud->ypos += (int)hud->block_height;
	}
}
