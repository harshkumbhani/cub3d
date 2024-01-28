#include "cub3d.h"

void	map_copy_create_square(char ***cpy_map, t_parsing *parser)
{
	allocate_map_with_two_extra_lines(cpy_map, parser);
	create_square_fill_with_spaces(*cpy_map, parser);
	
}
