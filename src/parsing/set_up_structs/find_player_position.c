/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/12 20:45:22 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	scan_line_for_player(t_map_content *line, t_game *game, int y);
static int	player_got_found(t_game *game);

void	find_player_position(t_game *game)
{
	int		y;

	if (game->map == NULL)
		return ;
	y = 0;
	while (game->map[y] != NULL && player_got_found(game) == false)
	{
		scan_line_for_player(game->map[y], game, y);
		y++;
	}
}

static void	scan_line_for_player(t_map_content *line, t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->map_dimensions[width])
	{
		if (line[x] == player)
		{
			game->player_position[x] = x;
			game->player_position[y] = y;
		}
		x++;
	}
}

static int	player_got_found(t_game *game)
{
	if (game->player_position[x] > 0 && game->player_position[y] > 0)
		return (true);
	return (false);
}
