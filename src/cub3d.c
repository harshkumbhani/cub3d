/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/01/30 16:31:10 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define R 20

void	handle_keyhook(mlx_key_data_t keydata, void *param)
{
	t_image	*image;

	image = (t_image *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(image->mlx);
	if (keydata.key == MLX_KEY_UP)
		image->player->instances->y -= 4;
	if (keydata.key == MLX_KEY_DOWN)
		image->player->instances->y += 4;
	if (keydata.key == MLX_KEY_RIGHT)
		image->player->instances->x += 4;
	if (keydata.key == MLX_KEY_LEFT)
		image->player->instances->x -= 4;
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
		i = x_pos;
		while (++i < x_pos + 50)
			mlx_put_pixel(image, i, j, 0xFF0000FF);
	}
}

void	render_player(t_image *player, int x_pos, int y_pos)
{
	mlx_texture_t *tex_player;

	tex_player = mlx_load_png("./src/player.png");
	player->player = mlx_texture_to_image(player->mlx, tex_player);
	mlx_delete_texture(tex_player);
	mlx_image_to_window(player->mlx, player->player, x_pos, y_pos);
}

void	render_map(t_image *image, int arr[10][13])
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
				render_block(image->background, x_pos, y_pos);
			if (arr[i][j] == 2)
				render_player(image, x_pos + 25, y_pos + 25);
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
	t_image	image;

	image = (t_image){};
	int x = -1;
	int	y = -1;
	int	map[10][13] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};

	image.mlx = mlx_init(50 * 13, 50 * 10, "Window", true);

	image.background = mlx_new_image(image.mlx, 50 * 13, 50 * 10);
	mlx_image_to_window(image.mlx, image.background, x, y);
	mlx_key_hook(image.mlx, handle_keyhook, &image);
	render_background(image.background);
	render_map(&image, map);
	mlx_loop(image.mlx);
	mlx_terminate(image.mlx);
	return (0);
}
