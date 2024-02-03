#include "cub3d.h"

void	add_string_at_top_and_bottom(char **cpy_map, t_parsing *parser)
{
	int		number_of_rows;

	if (parser->error_occurred == true)
		return ;
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	cpy_map[0] = ft_strdup(parser->line);
	if (cpy_map[0] == NULL)
		return (free(parser->line), parser_error(MEMORY_FAILED, NULL, parser));
	cpy_map[number_of_rows + 1] = ft_strdup(parser->line);
	if (cpy_map[number_of_rows + 1] == NULL)
		return (free(parser->line), parser_error(MEMORY_FAILED, NULL, parser));
}
