/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/10 17:11:52 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(mlx_image_t *image)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 50 * 10)
	{
		x = -1;
		while (++x < 50 * 13)
			mlx_put_pixel(image, x, y, 0x000000FF);
	}
}

void	render_block(mlx_image_t *image, int x_pos, int y_pos)
{
	int	i;
	int	j;

	j = y_pos;
	while (++j < y_pos + 50)
	{
		i = x_pos;
		while (++i < x_pos + 50)
			mlx_put_pixel(image, i, j, 0xFF0000FF);
	}
}

void	render_map(t_image *image, int arr[10][13])
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
			if (arr[i][j] == 1)
				render_block(image->background, x_pos, y_pos);
			if (arr[i][j] == 2)
				render_player(image, x_pos + 25, y_pos + 25);
			x_pos += 50;
		}
		y_pos += 50;
	}
}

void	render_player(t_image *player, int x_pos, int y_pos)
{
	mlx_texture_t	*tex_player;

	tex_player = mlx_load_png("./src/s_player.png");
	player->player = mlx_texture_to_image(player->mlx, tex_player);
	mlx_delete_texture(tex_player);
	mlx_image_to_window(player->mlx, player->player, x_pos, y_pos);
	player->line->x0 = x_pos + 5;
	player->line->y0 = y_pos + 5;
	render_line(player);
}
