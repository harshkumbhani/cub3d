#include "cub3d.h"

static void	create_line_of_filled_with_spaces(t_parsing *parser);
static void	add_spaces_to_top_and_bottom(char **map, t_parsing *parser);
static void	fill_line_with_spaces(t_parsing *parser);

void	add_line_of_spaces_at_top_and_bottom(char **cpy_map, t_parsing *parser)
{
	create_line_of_filled_with_spaces(parser);
	fill_line_with_spaces(parser);
	add_spaces_to_top_and_bottom(cpy_map, parser);
}

static void	create_line_of_filled_with_spaces(t_parsing *parser)
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

static void	add_spaces_to_top_and_bottom(char **map, t_parsing *parser)
{
	int		number_of_rows;

	if (parser->error_occurred == true)
		return ;
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	map[0] = ft_strdup(parser->line);
	if (map[0] == NULL)
		return (free(parser->line), parser_error(MEMORY_FAILED, NULL, parser));
	map[number_of_rows + 1] = ft_strdup(parser->line);
	if (map[number_of_rows + 1] == NULL)
		return (free(parser->line), parser_error(MEMORY_FAILED, NULL, parser));
}

