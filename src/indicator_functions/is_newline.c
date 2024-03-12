#include "cub3d.h"

int	is_newline(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "\n", 1) == 0)
		return (true);
	return (false);
}
