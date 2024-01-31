#include "cub3d.h"

static void	get_input(t_parsing *parser, int ac, char **av);

void	set_up_structs(t_parsing *parser, int ac, char **av)
{
	ft_bzero(parser, sizeof(t_parsing));
	get_input(parser, ac, av);
}

static void	get_input(t_parsing *parser, int ac, char **av)
{
	static t_input	input;

	ft_bzero(&input, sizeof(t_input));
	parser->input = &input;
	parser->input->ac = ac;
	parser->input->av = av;
}
