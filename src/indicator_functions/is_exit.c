#include "cub3d.h"

int	is_exit(char *line)
{
	if (ft_strncmp(line, "X", 1) == 0)
		return (true);
	return (false);
}
