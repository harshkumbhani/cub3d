/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 12:36:47 by hkumbhan         ###   ########.fr       */
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
		x =  -1;
		while (++x < width)
			mlx_put_pixel(image, x, y, 0x000000FF);
	}
}

void	render_block(t_cub3d *cub3d, int x_pos, int y_pos, int color)
{
	int	i;
	int	j;

	j = y_pos;
	while (++j < y_pos + HEIGHT / cub3d->meta_data->map_dimensions[1])
	{
		i = x_pos;
		while (++i < x_pos + WIDTH / cub3d->meta_data->map_dimensions[0])
			mlx_put_pixel(cub3d->image, i, j, color);
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
		while (++i < width)
			mlx_put_pixel(cub3d->player_window, x + i, y + j, 0x00FF00FF);
	}
}

void	render_minimap(t_cub3d *cub3d)
{
	int			i;
	int			j;
	int			player_size;
	t_minimap	*hud;

	j = -1;
	player_size = 5;
	hud = cub3d->hud;
	hud->block_width = MINIMAP_SIZE_X / (double)cub3d->meta_data->map_dimensions[width];
	hud->block_height = MINIMAP_SIZE_Y / (double)cub3d->meta_data->map_dimensions[height] - 1;
	render_background(cub3d->player_window, MINIMAP_SIZE_Y, MINIMAP_SIZE_X);
	hud->ypos = MINIMAP_POS_Y;
	while (++j < cub3d->meta_data->map_dimensions[1])
	{
		i = -1;
		hud->xpos = MINIMAP_POS_X;
		while (++i < cub3d->meta_data->map_dimensions[0])
		{
			if (cub3d->meta_data->map[j][i] == wall)
				draw_rectangle(cub3d, 0xFF0000FF);
			hud->xpos += (int)hud->block_width;
		}
		hud->ypos += (int)hud->block_height;
	}
	hud->player_xpos = MINIMAP_POS_X + (int)((cub3d->player->x_map) * hud->block_width);
	hud->player_ypos = MINIMAP_POS_Y + (int)(cub3d->player->y_map * hud->block_height);
	cub3d->line->x0 = hud->player_xpos;
	cub3d->line->y0 = hud->player_ypos;
	printf("x0: %d y0: %d\n", cub3d->line->x0, cub3d->line->y0);
	printf("player angle %2f\n", cub3d->player->pa);
	draw_player(cub3d, hud->player_xpos - player_size / 2, hud->player_ypos - player_size / 2, player_size);
	render_line(cub3d, hud->player_xpos + 20 * cos(cub3d->player->pa), hud->player_ypos + 20 * sin(cub3d->player->pa));
}

void	render_player(t_cub3d *mlx, int x_pos, int y_pos)
{
	mlx_texture_t	*tex_player;

	tex_player = mlx_load_png("./assets/s_player.png");
	mlx->player_window = mlx_texture_to_image(mlx->mlx, tex_player);
	mlx_delete_texture(tex_player);
	mlx_image_to_window(mlx->mlx, mlx->player_window, x_pos, y_pos);
	mlx->line->x0 = x_pos + 5;
	mlx->line->y0 = y_pos + 5;
}
