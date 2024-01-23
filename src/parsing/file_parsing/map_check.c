#include "cub3d.h"

void	map_parsing(t_parsing *parser)
{
	if (is_map_indicator(parser) == false || parser->error_occurred == true)
		return ;
	all_indicators_got_found(parser);
}
