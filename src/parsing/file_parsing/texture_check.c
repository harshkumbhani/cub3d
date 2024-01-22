#include "cub3d.h"

static void	tell_textrue_got_foud(t_parsing *parser);
static void	is_path_valide(t_parsing *parser);

void	texture_check(t_parsing *parser)
{
	if (parser->error_occurred == true || is_texture(parser->line) == false)
		return ;
	tell_textrue_got_foud(parser);
	is_path_valide(parser);
}

static void	tell_textrue_got_foud(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "NO", 2) == 0)
		parser->texture_indicator[north]++;
	else if (ft_strncmp(parser->line, "SO", 2) == 0)
		parser->texture_indicator[south]++;
	else if (ft_strncmp(parser->line, "WE", 2) == 0)
		parser->texture_indicator[west]++;
	else if (ft_strncmp(parser->line, "EA", 2) == 0)
		parser->texture_indicator[east]++;
}

static void	is_path_valide(t_parsing *parser)
{
	char	**path;
	int		fd;

	replace_newline_with_null_terminator(parser->line);
	path = ft_split(parser->line + 2, ' ');
	if (path == NULL)
		parser->error_occurred = true;//error message
	if (path[1] != NULL)
		parser->error_occurred = true;//error message
	fd = open(path[0], parser->fd);
	if (fd == -1)
	{
		parser->error_occurred = true;//error message
	}
	free_dubble_array(path);
}

