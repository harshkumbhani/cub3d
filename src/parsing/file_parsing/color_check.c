#include "cub3d.h"

static void	tell_color_indicator_got_found(t_parsing *parser);

void	color_check(t_parsing *parser)
{
	if (is_color_indicator(parser) == false || parser->error_occurred == true)
		return ;
	tell_color_indicator_got_found(parser);
	numbers_in_rgb_range_check(parser);
}

static void	tell_color_indicator_got_found(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "F ", 2) == 0)
		parser->color_indicator[floor]++;
	else if (ft_strncmp(parser->line, "C ", 2) == 0)
		parser->color_indicator[ceiling]++;
}
