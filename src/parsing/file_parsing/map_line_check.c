#include "cub3d.h"

static void	is_map_component_check(char c, t_parsing *parser);

void	map_line_check(t_parsing *parser)
{
	char	*tmp_line;

	if (parser->error_occurred == true || is_map_indicator(parser) == false)
		return ;
	tmp_line = parser->line;
	while(*tmp_line != '\n' && parser->error_occurred == false)
	{
		is_map_component_check(*tmp_line, parser);
		tmp_line++;
	}
}

static void	is_map_component_check(char c, t_parsing *parser)
{
	if (c == '1' || c == '0' || c == 'N' 
		|| c == 'S' || c == 'W' || c == 'E' || c == ' ')
		return ;
	parser->error_occurred = true;//print_error
}
