/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:38:36 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/12 17:33:23 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_execution(t_cub3d *mlx)
{
	mlx_delete_image(mlx->mlx, mlx->image);
	mlx_close_window(mlx->mlx);
	mlx_terminate(mlx->mlx);
}
