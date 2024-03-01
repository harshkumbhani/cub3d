#include "cub3d.h"

int	is_ammo(char *line)
{
	if (ft_strncmp(line, "A", 1) == 0)
		return (true);
	return (false);
}
