#include "cub3d.h"

static void	replace_newline_with_hidden_char(t_parsing *parser);

void	save_map_line(t_parsing *parser, char **tmp_map)
{
	if (is_map_indicator(parser) == false || parser->error_occurred == true)
		return ;
	replace_newline_with_hidden_char(parser);
	*tmp_map = ft_strjoin_mod(*tmp_map, parser->line);
}

static void	replace_newline_with_hidden_char(t_parsing *parser)
{
	int		i;

	i = 0;
	while (parser->line[i] != '\n' && parser->line[i] != '\0')
		i++;
	parser->line[i] = '\0';
	parser->line = ft_strjoin_mod(parser->line, "\1\0");
	if (parser->line == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
}
