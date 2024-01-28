#include "cub3d.h"

void	allocate_map_with_two_extra_lines(char ***cpy_map, t_parsing *parser)
{
	int		longest_line;
	int		rows;

	get_longest_line_in_map(parser->map, &longest_line);
	rows = count_doupple_arry_quantity(parser->map);
	*cpy_map = ft_calloc((rows * longest_line + 2), sizeof(char *));
	if (*cpy_map == NULL)
		parser_error(MEMORY_FAILED, NULL, parser);
}
