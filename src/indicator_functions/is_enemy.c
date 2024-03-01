#include "cub3d.h"

int	is_enemy(char *line)
{
	if ((ft_strncmp(line, "K", 1) == 0)
		|| (ft_strncmp(line, "R", 1) == 0)
		|| (ft_strncmp(line, "B", 1) == 0))
		return (true);
	return (false);
}
