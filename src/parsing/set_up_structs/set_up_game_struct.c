/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_game_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:55:36 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/14 00:04:18 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	null_game_struct(t_game *game);
static void	set_map_dimensions(t_game *game, t_parsing *parser);
static void	color_set(t_game *game, t_parsing *parser);
static void	directions_set(t_game *game, t_parsing *parser, char **copied_map);

void	set_up_game_struct(t_parsing *parser, t_game *game)
{
	char				**copied_map;

	null_game_struct(game);
	if (parser->error_occurred == true)
		return ;
	copy_map_with_two_extra_lines(&copied_map, parser);
	create_string_of_spaces(parser);
	add_string_at_top_and_bottom(copied_map, parser);
	fill_map_with_aligned_lines(copied_map, parser);
	enum_map_allocation(game, parser);
	fill_enum_map(game, copied_map);
	set_map_dimensions(game, parser);
	color_set(game, parser);
	directions_set(game, parser, copied_map);
	free_dubble_array(copied_map);
	game->cub_type = parser->cub_type;
}

static void	set_map_dimensions(t_game *game, t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	get_number_of_map_rows(parser->input->map, &(game->map_dimensions[height]));
	get_longest_line_in_map(parser->input->map, &(game->map_dimensions[width]));
	game->map_dimensions[width] += 2;
}

static void	color_set(t_game *game, t_parsing *parser)
{
	game->color[ground] = parser->input->ground;
	game->color[ceiling] = parser->input->ceiling;
}

static void	directions_set(t_game *game, t_parsing *parser, char **copied_map)
{
	if (parser->error_occurred == true)
		return ;
	game->directions = parser->input->texture;
	set_player_direction(game, parser, copied_map);
}

static void	null_game_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
}
