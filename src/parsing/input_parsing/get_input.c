#include "cub3d.h"

void	get_input(t_parsing *parser, int ac, char **av)
{
	ft_bzero(parser, sizeof(t_parsing));
	parser->ac = ac;
	parser->av = av;
}
