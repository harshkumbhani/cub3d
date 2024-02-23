/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/23 15:12:18 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_game(t_mlx *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_line		line;
	t_player	player;
	t_raycaster	raycaster;

	mlx = (t_mlx){};
	line = (t_line){};
	player = (t_player){};
	mlx.line = &line;
	mlx.player = &player;
	if (init(&mlx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	mlx_loop_hook(mlx.mlx, &loop_game, &mlx);
	mlx_loop(mlx.mlx);
	mlx_terminate(mlx.mlx);
//	image.mlx = mlx_init(WIDTH, HEIGHT, "minimap", true);
//	image.window_lin = mlx_new_image(image.mlx, WIDTH, HEIGHT);
//	image.background = mlx_new_image(image.mlx, WIDTH, HEIGHT);
//	line.line_window = (mlx_texture_t *)&image.window_lin;
//	mlx_image_to_window(image.mlx, image.window_lin, 0, 0);
//	mlx_image_to_window(image.mlx, image.background, x, y);
//	mlx_key_hook(image.mlx, handle_keyhook, &image);
//	render_map(&image, map);
//	mlx_loop(image.mlx);
//	mlx_terminate(image.mlx);
	return (0);
}
