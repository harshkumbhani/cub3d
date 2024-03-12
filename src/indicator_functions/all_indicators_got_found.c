#include "cub3d.h"

static int	all_color_indicators_found(t_parsing *parsing);
static int	texture_indicators_got_found(t_parsing *parsing);

void	all_indicators_got_found(t_parsing *parser)
{
	if (all_color_indicators_found(parser) == false
		|| texture_indicators_got_found(parser) == false)
		parser_error(NOT_ALL_INDICATORS, NULL, parser);
}

static int	all_color_indicators_found(t_parsing *parsing)
{
	if ((parsing->indicator->color[ceiling] != 1)
		|| (parsing->indicator->color[floor] != 1))
		return (false);
	return (true);
}

static int	texture_indicators_got_found(t_parsing *parsing)
{
	if ((parsing->indicator->texture[north] != 1)
		|| (parsing->indicator->texture[south] != 1)
		|| (parsing->indicator->texture[west] != 1)
		|| (parsing->indicator->texture[east] != 1))
		return (false);
	return (true);
}
