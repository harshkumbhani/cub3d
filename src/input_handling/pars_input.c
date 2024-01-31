#include "cub3d.h"

static void	file_type_check(t_parsing *parser);
static void	is_file_accessible_check(t_parsing *parser);

void	pars_input(t_parsing *parser)
{
	if (parser->input->ac != 2)
		parser_error(WRONG_AMOUNT_INPUT, NULL, parser);
	file_type_check(parser);
	is_file_accessible_check(parser);
}

static void	file_type_check(t_parsing *parser)
{
	int		str_len;

	if (parser->error_occurred == true)
		return ;
	str_len = ft_strlen(parser->input->av[1]);
	if (ft_strncmp((parser->input->av[1] + str_len - 4), ".cub", 4) != false)
		parser_error(NOT_CUB_FILE, parser->input->av[1], parser);
}

static void	is_file_accessible_check(t_parsing *parser)
{
	int fd;

	fd = open(parser->input->av[1], O_RDONLY);
	if (parser->error_occurred == true)
		return ;
	if (fd == -1)
		parser_error(INPUT_NO_FILE, parser->input->av[1], parser);
	close(fd);
}
