/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:15:16 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/27 14:50:33 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT) == true
		|| mlx_is_key_down(mlx->mlx, MLX_KEY_Q))
	{
		mlx->player->pa -= ROT_SPEED;
		if (mlx->player->pa < 0)
			mlx->player->pa += 2 * M_PI;
	}
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT) == true
		|| mlx_is_key_down(mlx->mlx, MLX_KEY_E))
	{
		mlx->player->pa += ROT_SPEED;
		if (mlx->player->pa > 2 * M_PI)
			mlx->player->pa -= 2 * M_PI;
	}
}

void	move_frd_back(t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_W) == true)
	{
		move_x = cos(mlx->player->pa) * PLAYER_SPEED;
		move_y = sin(mlx->player->pa) * PLAYER_SPEED;
	}
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_S) == true)
	{
		move_x = -cos(mlx->player->pa) * PLAYER_SPEED;
		move_y = -sin(mlx->player->pa) * PLAYER_SPEED;
	}
	mlx->player->x_px = roundf(mlx->player->x_px + move_x);
	mlx->player->y_px = roundf(mlx->player->y_px + move_y);
}

void	move_left_right(t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D) == true)
	{
		move_x = -sin(mlx->player->pa) * PLAYER_SPEED;
		move_y = cos(mlx->player->pa) * PLAYER_SPEED;
	}
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_A) == true)
	{
		move_x = sin(mlx->player->pa) * PLAYER_SPEED;
		move_y = -cos(mlx->player->pa) * PLAYER_SPEED;
	}
	mlx->player->x_px = roundf(mlx->player->x_px + move_x);
	mlx->player->y_px = roundf(mlx->player->y_px + move_y);
}

void	handle_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		free_and_exit(mlx);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_Q)
		rotate_player(mlx);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_E)
		rotate_player(mlx);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		move_frd_back(mlx);
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		move_left_right(mlx);
}
