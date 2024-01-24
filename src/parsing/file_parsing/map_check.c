#include "cub3d.h"

static void	set_map_status(t_parsing *parser);
static void	new_line_in_map(t_parsing *parser);

void	map_check(t_parsing *parser)
{
	set_map_status(parser);
	if (parser->map[start] == false || parser->error_occurred == true)
		return ;
	all_indicators_got_found(parser);
	new_line_in_map(parser);
}

static void	set_map_status(t_parsing *parser)
{
	if (is_map_indicator(parser) == true && parser->map[start] == false)
		parser->map[start] = true;
	else if (parser->map[start] == true && parser->line[0] == '\n')
		parser->map[end] = true;
}

static void	new_line_in_map(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	if (parser->map[end] == true && is_map_indicator(parser) == true)
	{
		parser->error_occurred = true; //print_error
	}
}
