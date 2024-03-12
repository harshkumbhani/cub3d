#include "cub3d.h"

int	is_color_indicator(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "F ", 2) == 0
		|| ft_strncmp(parser->line, "C ", 2) == 0)
		return (true);
	return (false);
}
