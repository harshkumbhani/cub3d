#include "cub3d.h"

static void	get_input(t_parsing *parser, int ac, char **av);
static void	get_color_struct(t_parsing *parser);
static void	get_texture_struct(t_parsing *parser);
static void	indicator_struct_set_up(t_parsing *parser);

void	set_up_parser_struct(t_parsing *parser, int ac, char **av)
{
	ft_bzero(parser, sizeof(t_parsing));
	get_input(parser, ac, av);
	get_color_struct(parser);
	get_texture_struct(parser);
	indicator_struct_set_up(parser);
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
	static t_color	ground_struct;
	static t_color	ceiling_struct;

	ft_bzero(&ground_struct, sizeof(t_color));
	ft_bzero(&ceiling_struct, sizeof(t_color));
	parser->input->ceiling = &ceiling_struct;
	parser->input->ground = &ground_struct;
}

static void	get_texture_struct(t_parsing *parser)
{
	static t_directions	texture;

	ft_bzero(&texture, sizeof(t_directions));
	parser->input->texture = &texture;
}

static void	indicator_struct_set_up(t_parsing *parser)
{
	static t_indicator	indicator_struct;

	ft_bzero(&indicator_struct, sizeof(t_indicator));
	parser->indicator = &indicator_struct;
}
