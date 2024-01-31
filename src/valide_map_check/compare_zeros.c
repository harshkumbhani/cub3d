#include "cub3d.h"

void	compare_zeros(int zero_before, int zero_after, t_parsing *parser)
{
	if (zero_before != zero_after)
		parser_error(MAP_IS_NOT_CLOSED, NULL, parser);
}
