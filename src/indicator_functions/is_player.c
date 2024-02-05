#include "cub3d.h"

int	is_player(char *line, t_parsing *parser)
{
	if (((ft_strncmp(line, "N", 1) == 0)
			|| (ft_strncmp(line, "S", 1) == 0)
			|| (ft_strncmp(line, "W", 1) == 0)
			|| (ft_strncmp(line, "E", 1) == 0))
		&& is_texture(parser) == false)
		return (true);
	return (false);
}
