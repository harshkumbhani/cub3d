/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_spaces_in_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:56:00 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:58:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_position(char **map, int *y, int *x, t_parsing *parser);
static void	scan_line_for_player(char *line, int *x, t_parsing *parser);
static void	flood_fill_check_space(char **map, int y, int x, t_parsing *parser);
static int	leave_space_flood_fill(char **map, int x, int y, t_parsing *parser);

void	check_for_spaces_in_map(char **copied_map, t_parsing *parser)
{
	int		x;
	int		y;

	if (parser->error_occurred == true)
		return ;
	get_player_position(copied_map, &y, &x, parser);
	flood_fill_check_space(copied_map, y, x, parser);
}

static void	get_player_position(char **map, int *y, int *x, t_parsing *parser)
{
	*y = 0;
	*x = 0;
	parser->player_found = false;
	while (map[*y] != NULL && parser->player_found == false)
	{
		scan_line_for_player(map[*y], x, parser);
		(*y)++;
	}
	*y -= 1;
}

static void	scan_line_for_player(char *line, int *x, t_parsing *parser)
{
	*x = 0;
	while (line[*x] != '\0')
	{
		if (is_player(line + (*x), parser) == true)
		{
			parser->player_found = true;
			return ;
		}
		(*x)++;
	}
}

static void	flood_fill_check_space(char **map, int y, int x, t_parsing *parser)
{
	if (leave_space_flood_fill(map, x, y, parser) == true)
		return ;
	else if (map[y][x] == ' ')
		return (parser_error(SPACE_IN_MAP, map[y], parser));
	map[y][x] = 'F';
	flood_fill_check_space(map, y, x - 1, parser);
	flood_fill_check_space(map, y, x + 1, parser);
	flood_fill_check_space(map, y - 1, x, parser);
	flood_fill_check_space(map, y + 1, x, parser);
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
	return (false);
}
