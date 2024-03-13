/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:32:11 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/14 00:10:44 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_minimap_player(t_cub3d *cub3d)
{
	int		player_block[2];
	int		minimap_block[2];
	double	minimap_offset[2];

	render_background(cub3d->player_window, MINIMAP_SIZE_Y, MINIMAP_SIZE_X);
	player_block[0] = cub3d->player->x_px & 0x3F;
	player_block[1] = cub3d->player->y_px & 0x3F;
	minimap_block[0] = (cub3d->player->x_map - 1) * cub3d->hud->block_width;
	minimap_block[1] = cub3d->player->y_map * cub3d->hud->block_height;
	minimap_offset[0] = (double)player_block[0]
		/ BLOCK_SIZE * cub3d->hud->block_width;
	minimap_offset[1] = (double)player_block[1]
		/ BLOCK_SIZE * cub3d->hud->block_height;
	cub3d->hud->player_xpos = minimap_block[0] + (int)minimap_offset[0];
	cub3d->hud->player_ypos = minimap_block[1] + (int)minimap_offset[1];
	cub3d->line->x0 = cub3d->hud->player_xpos;
	cub3d->line->y0 = cub3d->hud->player_ypos;
	draw_player(cub3d, cub3d->hud->player_xpos - (5 / 2),
		cub3d->hud->player_ypos - (5 / 2), 5);
	render_line(cub3d, cub3d->hud->player_xpos + 20 * cos(cub3d->player->pa),
		cub3d->hud->player_ypos + 20 * sin(cub3d->player->pa));
}
