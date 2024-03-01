#include "cub3d.h"

void	get_longest_line_in_map(char **map, int *line_len)
{
	int		i;
	size_t	longes_line;

	i = 0;
	longes_line = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) > longes_line)
			longes_line = ft_strlen(map[i]);
		i++;
	}
	*line_len = longes_line;
}
