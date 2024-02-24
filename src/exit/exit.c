/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:38:36 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/02/24 07:40:49 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_exit(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlx, mlx->image);
	mlx_close_window(mlx->mlx);
	mlx_terminate(mlx->mlx);
	exit(EXIT_SUCCESS);
}