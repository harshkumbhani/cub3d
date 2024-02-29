/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/29 09:35:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(mlx_image_t *image)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(image, x, y, 0x000000FF);
	}
}

void	render_block(mlx_image_t *image, int x_pos, int y_pos, int color)
{
	int	i;
	int	j;

	j = y_pos;
	while (++j < y_pos + BLOCK_SIZE)
	{
		i = x_pos;
		while (++i < x_pos + BLOCK_SIZE)
			mlx_put_pixel(image, i, j, color);
	}
}

void	render_map(t_mlx *mlx)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	i = -1;
	y_pos = 0;
	while (++i < 10)
	{
		j = -1;
		x_pos = 0;
		while (++j < 13)
		{
			if (mlx->map[i][j] == 1)
				render_block(mlx->image, x_pos, y_pos, 0xFFFFFFFF);
			//if (mlx->map[i][j] == 2)
			//	render_player(mlx, x_pos + BLOCK_SIZE / 2, y_pos + BLOCK_SIZE / 2);
			x_pos += BLOCK_SIZE;
		}
		y_pos += BLOCK_SIZE;
	}
}

void	render_player(t_mlx *mlx, int x_pos, int y_pos)
{
	mlx_texture_t	*tex_player;

	tex_player = mlx_load_png("./src/s_player.png");
	mlx->player_window = mlx_texture_to_image(mlx->mlx, tex_player);
	mlx_delete_texture(tex_player);
	mlx_image_to_window(mlx->mlx, mlx->player_window, x_pos, y_pos);
	mlx->line->x0 = x_pos + 5;
	mlx->line->y0 = y_pos + 5;
}
