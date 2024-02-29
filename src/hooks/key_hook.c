/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:15:16 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/29 11:15:19 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_mlx *mlx, int direction)
{
	mlx->player->pa += direction * ROT_SPEED;
	if (mlx->player->pa < 0)
		mlx->player->pa += 2 * M_PI;
	else if (mlx->player->pa > 2 * M_PI)
			mlx->player->pa -= 2 * M_PI;
}

void	move_player(t_mlx *mlx, double dir_x, double dir_y)
{
	double	move_x;
	double	move_y;

	move_x = dir_x * PLAYER_SPEED;
	move_y = dir_y * PLAYER_SPEED;
	if (collision_with_wall(mlx, move_x, move_y) == false)
	{
		mlx->player->x_px = roundf(mlx->player->x_px + move_x);
		mlx->player->y_px = roundf(mlx->player->y_px + move_y);
	}
}

void	handle_movement(t_mlx *mlx)
{
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
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		free_and_exit(mlx);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_Q)
		rotate_player(mlx, -1);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_E)
		rotate_player(mlx, 1);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S ||
		keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		handle_movement(mlx);
}
