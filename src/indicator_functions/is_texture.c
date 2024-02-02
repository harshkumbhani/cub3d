#include "cub3d.h"

int	is_texture(t_parsing *parser)
{
	if ((ft_strncmp(parser->line, "NO ", 3) == 0)
			|| (ft_strncmp(parser->line, "SO ", 3) == 0)
			|| (ft_strncmp(parser->line, "WE ", 3) == 0)
			|| (ft_strncmp(parser->line, "EA ", 3) == 0)
			|| (ft_strncmp(parser->line, "DO ", 3) == 0))
		return (true);
	return (false);
}
