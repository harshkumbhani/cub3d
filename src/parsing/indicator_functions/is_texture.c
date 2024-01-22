#include "cub3d.h"

int	is_texture(char *line)
{
	if ((ft_strncmp(line, "NO ", 3) == 0)
			|| (ft_strncmp(line, "SO ", 3) == 0)
			|| (ft_strncmp(line, "WE ", 3) == 0)
			|| (ft_strncmp(line, "EA ", 3) == 0))
		return (true);
	return (false);
}
