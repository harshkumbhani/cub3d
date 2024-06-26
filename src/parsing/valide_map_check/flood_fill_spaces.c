/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:56:13 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:56:14 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	leave_space_flood_fill(char **map, int x, int y, t_parsing *parser);

void	flood_fill_spaces(char **map, int x, int y, t_parsing *parser)
{
	if (leave_space_flood_fill(map, x, y, parser) == true)
		return ;
	map[y][x] = 'F';
	flood_fill_spaces(map, x - 1, y, parser);
	flood_fill_spaces(map, x + 1, y, parser);
	flood_fill_spaces(map, x, y - 1, parser);
	flood_fill_spaces(map, x, y + 1, parser);
}

static int	leave_space_flood_fill(char **map, int x, int y, t_parsing *parser)
{
	if (parser->error_occurred == true)
		return (true);
	else if (x < 0 || y < 0)
		return (true);
	else if (x >= (int) ft_strlen(map[0]))
		return (true);
	else if (y >= count_doupple_arry_quantity(map))
		return (true);
	else if (map[y][x] == 'F' || map[y][x] == '1')
		return (true);
	else if (map[y][x] == '0')
		return (parser_error(MAP_IS_NOT_CLOSED, NULL, parser), true);
	else if (is_player((map[y] + x), parser) == true)
		return (parser_error(PLAYER_OUT_OF_MAP, (map[y] + x), parser), true);
	return (false);
}
