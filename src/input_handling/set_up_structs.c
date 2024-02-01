#include "cub3d.h"

static void	get_input(t_parsing *parser, int ac, char **av);
static void	get_color_struct(t_parsing *parser);

void	set_up_structs(t_parsing *parser, int ac, char **av)
{
	ft_bzero(parser, sizeof(t_parsing));
	get_input(parser, ac, av);
	get_color_struct(parser);
}

static void	get_input(t_parsing *parser, int ac, char **av)
{
	static t_input	input;

	ft_bzero(&input, sizeof(t_input));
	parser->input = &input;
	parser->input->ac = ac;
	parser->input->av = av;
}

static void	get_color_struct(t_parsing *parser)
{
	static t_color floor_struct;
	static t_color ceiling_struct;

	parser->color[floor] = &floor_struct;
	parser->color[ceiling] = &ceiling_struct;
}
