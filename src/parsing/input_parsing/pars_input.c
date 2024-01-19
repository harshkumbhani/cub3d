#include "cub3d.h"

static void	file_type_check(t_parsing *parser);
static void	is_file_accessible_check(t_parsing *parser);

void	pars_input(t_parsing *parser)
{
	if (parser->ac != 2)
		parser->error_occurred = true;//error message
	file_type_check(parser);
	is_file_accessible_check(parser);
}

static void	file_type_check(t_parsing *parser)
{
	int		str_len;

	if (parser->error_occurred == true)
		return ;
	str_len = ft_strlen(parser->av[1]);
	if (ft_strncmp((parser->av[1] + str_len - 4), ".cub", 4) != false)
		parser->error_occurred = true;
}

static void	is_file_accessible_check(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	if (open(parser->av[1], 0) == -1)
		parser->error_occurred = true; //print error
}
