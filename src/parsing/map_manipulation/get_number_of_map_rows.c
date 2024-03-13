#include "cub3d.h"

void	get_number_of_map_rows(char **map, int *number_rows)
{
	if (map == NULL || *map == NULL)
	{
		*number_rows = 0;
		return ;
	}
	(*number_rows) = count_doupple_arry_quantity(map);
}
