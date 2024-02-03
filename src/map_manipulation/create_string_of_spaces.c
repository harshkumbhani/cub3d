#include "cub3d.h"

void	create_string_of_spaces(t_parsing *parser)
{
	int		number_of_rows;
	int		longest_line;

	if (parser->error_occurred == true)
		return ;
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	get_longest_line_in_map(parser->input->map, &longest_line);
	parser->line = (char *) malloc((longest_line + 3) * sizeof(char));
	if (parser->line == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	parser->line[longest_line + 2] = '\0';
}

static void	fill_line_with_spaces(t_parsing *parser)
{
	int	i;

	i = 0;
	while(parser->line[i] != '\0')
	{
		parser->line[i] = ' ';
		i++;
	}
}
