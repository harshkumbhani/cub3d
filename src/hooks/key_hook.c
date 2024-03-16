/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:15:16 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/16 12:21:14 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub3d *mlx, int direction)
{
	// mlx->player->player_moved_in_map = true;
	mlx->player->pa += direction * ROT_SPEED;
	if (mlx->player->pa < 0)
		mlx->player->pa += 2 * M_PI;
	else if (mlx->player->pa > 2 * M_PI)
		mlx->player->pa -= 2 * M_PI;
}

void	move_player(t_cub3d *mlx, double dir_x, double dir_y)
{
	double	move_x;
	double	move_y;

	move_x = dir_x * PLAYER_SPEED;
	move_y = dir_y * PLAYER_SPEED;
	if (collision_with_wall(mlx, move_x, move_y) == false)
	{
		mlx->player->player_moved_in_map = true;
		mlx->player->x_px = roundf(mlx->player->x_px + move_x);
		mlx->player->y_px = roundf(mlx->player->y_px + move_y);
	}
}

void	handle_movement(t_cub3d *mlx)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT) == true)
		rotate_player(mlx, -1);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT) == true)
		rotate_player(mlx, 1);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_W) == true)
		move_player(mlx, cos(mlx->player->pa), sin(mlx->player->pa));
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_S) == true)
		move_player(mlx, -cos(mlx->player->pa), -sin(mlx->player->pa));
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_A) == true)
		move_player(mlx, sin(mlx->player->pa), -cos(mlx->player->pa));
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D) == true)
		move_player(mlx, -sin(mlx->player->pa), cos(mlx->player->pa));
}

void	handle_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*mlx;

	mlx = (t_cub3d *)param;
	mlx->player->player_moved_in_map = false;
	if (keydata.key == MLX_KEY_ESCAPE)
		free_execution(mlx, EXIT_SUCCESS);
}
