#include "cub3d.h"

int	is_door(char *line)
{
	if (ft_strncmp(line, "D", 1) == 0 && ft_strncmp(line, "DO", 1) != 0)
		return (true);
	return (false);
}
