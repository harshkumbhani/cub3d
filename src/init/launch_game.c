/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:48:11 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 03:42:14 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_cub3d *mlx);
static int	load_textures(t_cub3d *cub3d);
static void	loop_game(void *param);

int	launch_game(t_cub3d *cub3d)
{
	init_data(cub3d);
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (cub3d->mlx == NULL)
		return (printf("%s%s%s", RED, FATAL_MLX_INIT, RESET), EXIT_FAILURE);
	if (init_mlx(cub3d) == EXIT_FAILURE)
		return (printf("%s%s%s", RED, FATAL_NEW_IMAGE, RESET), EXIT_FAILURE);
	if (load_textures(cub3d) == EXIT_FAILURE)
		return (printf("%s%s%s", RED, FATAL_TEX_LOAD, RESET), EXIT_FAILURE);
	mlx_loop_hook(cub3d->mlx, &loop_game, cub3d);
	mlx_key_hook(cub3d->mlx, handle_keyhook, cub3d);
	mlx_loop(cub3d->mlx);
	return (EXIT_SUCCESS);
}

int	init_mlx(t_cub3d *mlx)
{
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->image == NULL)
		return (EXIT_FAILURE);
	mlx->line_window = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->line_window == NULL)
		return (EXIT_FAILURE);
	mlx_image_to_window(mlx->mlx, mlx->line_window, 0, 0);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	mlx->line_window->instances->z = 0;
	mlx->image->instances->z = 1;
	render_map(mlx);
	return (EXIT_SUCCESS);
}

int	load_textures(t_cub3d *cub3d)
{
	t_directions	*directions;

	directions = cub3d->meta_data->directions;
	cub3d->meta_data->direction_img[NORTH] = mlx_load_png(directions->north);
	if (cub3d->meta_data->direction_img[NORTH] == NULL)
		return (EXIT_FAILURE);
	cub3d->meta_data->direction_img[SOUTH] = mlx_load_png(directions->south);
	if (cub3d->meta_data->direction_img[SOUTH] == NULL)
		return (EXIT_FAILURE);
	cub3d->meta_data->direction_img[EAST] = mlx_load_png(directions->east);
	if (cub3d->meta_data->direction_img[EAST] == NULL)
		return (EXIT_FAILURE);
	cub3d->meta_data->direction_img[WEST] = mlx_load_png(directions->west);
	if (cub3d->meta_data->direction_img[WEST] == NULL)
		return (EXIT_FAILURE);
	cub3d->wall = mlx_load_png(directions->east);
	return (EXIT_SUCCESS);
}

void	loop_game(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	raycaster(cub3d);
}

	//if (parser.error_occurred == false)
	//{
		//if (init(&cub3d) == EXIT_FAILURE)
		//	return (EXIT_FAILURE);
		//cub3d.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
		//init_mlx(&cub3d);
		//mlx_loop_hook(cub3d.mlx, &loop_game, &cub3d);
		//mlx_key_hook(cub3d.mlx, handle_keyhook, &cub3d);
		//mlx_loop(cub3d.mlx);
		//free_execution(&cub3d);
	//}