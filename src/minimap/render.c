/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:11:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/24 13:29:26 by hkumbhan         ###   ########.fr       */
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

//void	render_block(mlx_image_t *image, int x_pos, int y_pos)
//{
//	int	i;
//	int	j;

//	j = y_pos;
//	while (++j < y_pos + BLOCK_SIZE)
//	{
//		i = x_pos;
//		while (++i < x_pos + BLOCK_SIZE)
//			mlx_put_pixel(image, i, j, 0xFFFFFFFF);
//	}
//}

//void	render_map(t_image *image, int arr[10][13])
//{
//	int	i;
//	int	j;
//	int	x_pos;
//	int	y_pos;

//	i = -1;
//	y_pos = 0;
//	while (++i < 10)
//	{
//		j = -1;
//		x_pos = 0;
//		while (++j < 13)
//		{
//			if (arr[i][j] == 1)
//				render_block(image->background, x_pos, y_pos);
//			if (arr[i][j] == 2)
//				render_player(image, x_pos + BLOCK_SIZE / 2, y_pos + BLOCK_SIZE / 2);
//			x_pos += BLOCK_SIZE;
//		}
//		y_pos += BLOCK_SIZE;
//	}
//}

//void	render_player(t_image *player, int x_pos, int y_pos)
//{
//	mlx_texture_t	*tex_player;

//	tex_player = mlx_load_png("./src/s_player.png");
//	player->player = mlx_texture_to_image(player->mlx, tex_player);
//	mlx_delete_texture(tex_player);
//	mlx_image_to_window(player->mlx, player->player, x_pos, y_pos);
//	player->line->x0 = x_pos + 5;
//	player->line->y0 = y_pos + 5;
//	player->hero->pdx = cos(player->angle) * 5;
//	player->hero->pdy = sin(player->angle) * 5;
//	render_line(player->line, player->line->x0 + 5 * player->hero->pdx,
//		player->line->y0 + 5 * player->hero->pdy);
//}
