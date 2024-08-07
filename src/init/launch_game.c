/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:48:11 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/16 12:21:32 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_cub3d *mlx);
static int	load_textures(t_cub3d *cub3d);
static void	loop_game(void *param);
static void	load_music(int map_type);
// static void	movement_hook(t_cub3d *cub3d);

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
	load_music(cub3d->meta_data->cub_type);
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
	mlx->minimap = mlx_new_image(mlx->mlx, MINIMAP_SIZE_X, MINIMAP_SIZE_Y);
	if (mlx->minimap == NULL)
		return (EXIT_FAILURE);
	mlx->player_window = mlx_new_image(mlx->mlx,
			MINIMAP_SIZE_X, MINIMAP_SIZE_Y);
	if (mlx->player_window == NULL)
		return (EXIT_FAILURE);
	mlx_image_to_window(mlx->mlx, mlx->player_window,
		MINIMAP_POS_X, MINIMAP_POS_Y);
	mlx_image_to_window(mlx->mlx, mlx->minimap, MINIMAP_POS_X, MINIMAP_POS_Y);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	mlx->image->instances->z = 0;
	mlx->minimap->instances->z = 2;
	mlx->player_window->instances->z = 1;
	render_minimap(mlx);
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
	return (EXIT_SUCCESS);
}

void	load_music(int map_type)
{
	if (map_type == CAFE_CUB)
		system("afplay assets/cafe/cafe.wav&");
	else if (map_type == CHOPIN_CUB)
		system("afplay assets/chopin/chopin.wav&");
	else if (map_type == SEA_CUB)
		system("afplay assets/sea/sea.wav&");
}

void	loop_game(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	raycaster(cub3d);
	handle_movement(cub3d);
	update_minimap_player(cub3d);
}
