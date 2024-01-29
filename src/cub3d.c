/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/01/29 16:04:28 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define R 250

void	handle_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window((mlx_t *)param);
}

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
		printf("render block\n");
		i = x_pos;
		while (++i < x_pos + 50)
			mlx_put_pixel(image, i, j, 0xFF0000FF);
	}
}

void	render_map(mlx_image_t *image, int arr[10][13])
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	i = -1;
	y_pos = 0;
	x_pos = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 13)
		{
			if (arr[i][j] == 1)
			{
				printf("pos[%d][%d]: %d\n", i, j, arr[i][j]);
				printf("x_pos: %d y_pos: %d\n", x_pos, y_pos);
				render_block(image, x_pos, y_pos);
			}
			x_pos += 50;
		}
		x_pos = 0;
		y_pos += 50;
	}
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	int x = -1;
	int	y = -1;
	int	map[10][13] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
	mlx_t	*mlx;

	mlx = mlx_init(50 * 13, 50 * 10, "Window", true);
	mlx_image_t	*image;

	image = mlx_new_image(mlx, 50 * 13, 50 * 10);
	mlx_image_to_window(mlx, image, x, y);
	mlx_key_hook(mlx, handle_keyhook, mlx);
	render_background(image);
	//render_circle(image, WIDTH / 2, HEIGHT / 2);
	render_map(image, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
