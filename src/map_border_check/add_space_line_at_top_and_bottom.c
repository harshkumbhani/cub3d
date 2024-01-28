#include "cub3d.h"

void	add_space_line_at_top_and_bottom(char ***cpy_map, char *space_line,
		int longest_line)
{
	free(*cpy_map[0]);
	(*cpy_map)[0] = ft_strdup(space_line);
	*cpy_map[longest_line - 1] = ft_strdup(space_line);
}
