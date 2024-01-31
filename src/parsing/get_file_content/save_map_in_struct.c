#include "cub3d.h"

void	save_map_in_struct(t_parsing *parser, char **tmp_map)
{
	if (parser->error_occurred == true)
		return (free(tmp_map));
	parser->input->map = ft_split(*tmp_map, '\1');
	if (parser->input->map == NULL)
		parser_error(MEMORY_FAILED, NULL, parser);
	free(*tmp_map);
	tmp_map = NULL;
}
