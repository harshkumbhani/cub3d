#include "cub3d.h"

t_parsing	**get_parser_struct(void)
{
	static t_parsing	*parser;

	return (&parser);
}
