#include "cub3d.h"

static void	set_map_dimensions(t_game *game, t_parsing *parser);
static void	color_set(t_game *game, t_parsing *parser);
static void	directions_set(t_game *game, t_parsing *parser);

void	set_up_game_struct(t_parsing *parser, t_game *game)
{
	char				**copied_map;

	if (parser->error_occurred == true)
		return ;
	copy_map_with_two_extra_lines(&copied_map, parser);
	create_string_of_spaces(parser);
	add_string_at_top_and_bottom(copied_map, parser);
	fill_map_with_aligned_lines(copied_map, parser);
	enum_map_allocation(game, parser);
	fill_enum_map(game, copied_map);
	free_dubble_array(copied_map);
	set_map_dimensions(game, parser);
	color_set(game, parser);
	directions_set(game, parser);
}

static void	set_map_dimensions(t_game *game, t_parsing *parser)
{
	get_number_of_map_rows(parser->input->map, &(game->map_dimensions[height]));
	get_longest_line_in_map(parser->input->map, &(game->map_dimensions[width]));
	game->map_dimensions[width] += 2;
}

static void	color_set(t_game *game, t_parsing *parser)
{
	game->color[floor] = parser->input->floor;
	game->color[ceiling] = parser->input->ceiling;
}

static void	directions_set(t_game *game, t_parsing *parser)
{
	game->directions = parser->input->texture;
}
