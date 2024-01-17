#include "cub3d.h"

static int	file_type(t_parsing *parser);

void	pars_input(t_parsing *parser)
{
	if (parser->ac != 2)
	{
		parser->error_occurred = true;
		return ;
	}
	if (file_type(parser) == false)
	{
		parser->error_occurred = true;
		return ;
	}
}

static int	file_type(t_parsing *parser)
{
	int		str_len;

	str_len = ft_strlen(parser->av[1]);
	if (ft_strncmp((parser->av[1] + str_len - 4), ".cub", 4) != false)
		return (false);
	return (true);
}
