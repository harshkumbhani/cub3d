#include "cub3d.h"

void	fill_line_with_spaces(char *line, int line_len)
{
	int	i;

	i = 0;
	while (i < line_len)
	{
		line[i] = ' ';
		i++;
	}
}
