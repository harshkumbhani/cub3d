#include "cub3d.h"

void	get_number_of_map_rows(t_parsing *parser, int *number_rows)
{
	(*number_rows) = count_doupple_arry_quantity(parser->map);
}
