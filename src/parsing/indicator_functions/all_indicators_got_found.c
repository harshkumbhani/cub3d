#include "cub3d.h"

static int	all_color_indicators_found(t_parsing *parsing);
static int	texture_indicators_got_found(t_parsing *parsing);

int	all_indicators_got_found(t_parsing *parser)
{
	if (all_color_indicators_found(parser) == false
		|| texture_indicators_got_found(parser) == false)
		return (false);
	return (true);
}

static int	all_color_indicators_found(t_parsing *parsing)
{
	if ((parsing->color_indicator[ceiling] != 1)
		|| (parsing->color_indicator[floor] != 1))
		return (false);
	return (true);
}

static int	texture_indicators_got_found(t_parsing *parsing)
{
	if ((parsing->texture_indicator[north] != 1)
		|| (parsing->texture_indicator[south] != 1)
		|| (parsing->texture_indicator[west] != 1)
		|| (parsing->texture_indicator[east] != 1))
		return (false);
	return (true);
}
