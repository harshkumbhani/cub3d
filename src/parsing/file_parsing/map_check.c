#include "cub3d.h"

static void	set_map_status(t_parsing *parser);
static void	new_line_in_map(t_parsing *parser);
static void	found_player_check(t_parsing *parser);

void	map_check(t_parsing *parser)
{
	set_map_status(parser);
	if (parser->map_indicator[start] == false || parser->error_occurred == true)
		return ;
	all_indicators_got_found(parser);
	new_line_in_map(parser);
	map_line_check(parser);
	found_player_check(parser);
}

static void	set_map_status(t_parsing *parser)
{
	if (is_map_indicator(parser) == true
		&& parser->map_indicator[start] == false)
		parser->map_indicator[start] = true;
	else if (parser->map_indicator[start] == true && parser->line[0] == '\n')
		parser->map_indicator[end] = true;
}

static void	new_line_in_map(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	if (parser->map_indicator[end] == true && is_map_indicator(parser) == true)
		parser_error(NEWLINE_IN_MAP, NULL, parser);
}

static void	found_player_check(t_parsing *parser)
{
	if (parser->map_indicator[end] == true
		&& parser->map_indicator[player] != 1)
		return (parser_error(NO_PLAYER_FOUND, parser->line, parser));
}
