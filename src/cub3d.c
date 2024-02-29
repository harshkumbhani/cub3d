/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/27 17:05:06 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_game(void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	//mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	//mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	//mlx_image_to_window(mlx->mlx, mlx->line_window, 0, 0);
	//render_map(mlx);
	//printf("angle: %.2f\n", mlx->player->pa);
	raycaster(mlx);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->line_window = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx->mlx, mlx->line_window, 0, 0);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	mlx->line_window->instances->z = 0;
	mlx->image->instances->z = 1;
	render_map(mlx);
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
	raycaster = (t_raycaster){};
	mlx.line = &line;
	mlx.player = &player;
	mlx.raycaster = &raycaster;
	if (init(&mlx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	init_mlx(&mlx);
	mlx_loop_hook(mlx.mlx, &loop_game, &mlx);
	mlx_key_hook(mlx.mlx, handle_keyhook, &mlx);
	mlx_loop(mlx.mlx);
	free_and_exit(&mlx);
	return (0);
}
