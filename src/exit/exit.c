/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:38:36 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 19:00:58 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_execution(t_cub3d *cub3d, int exit_flag)
{
	int			i;
	t_parsing	**parser;

	parser = get_parser_struct();
	system("killall afplay");
	i = -1;
	while (++i < 4)
	{
		if (cub3d->meta_data->direction_img[i] != NULL)
			mlx_delete_texture(cub3d->meta_data->direction_img[i]);
	}
	if (cub3d->image != NULL)
		mlx_delete_image(cub3d->mlx, cub3d->image);
	if (cub3d->player_window != NULL)
		mlx_delete_image(cub3d->mlx, cub3d->player_window);
	if (cub3d->minimap != NULL)
		mlx_delete_image(cub3d->mlx, cub3d->minimap);
	mlx_close_window(cub3d->mlx);
	mlx_terminate(cub3d->mlx);
	free_structs(cub3d->meta_data, *parser);
	exit(exit_flag);
}
