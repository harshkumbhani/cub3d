#include "cub3d.h"

static void	scan_line_for_zeros(char *line, int *number_of_zero);

void	count_zeros_in_map(int *number_of_zero, char **map)
{
	int		i;

	i = 0;
	*number_of_zero = 0;
	while (map[i] != NULL)
	{
		scan_line_for_zeros(map[i], number_of_zero);
		i++;
	}
}

static void	scan_line_for_zeros(char *line, int *number_of_zero)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0')
			(*number_of_zero)++;
		i++;
	}
}
