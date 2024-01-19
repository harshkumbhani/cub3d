#include "cub3d.h"

static void	tell_textrue_got_foud(t_parsing *parser, char *line);
static void	is_path_valide(t_parsing *parser, char *line);

void	texture_check(t_parsing *parser, char *line)
{
	if (parser->error_occurred == true || is_texture(line) == true)
		return ;
	tell_textrue_got_foud(parser, line);
	is_path_valide(parser, line);
}

static void	tell_textrue_got_foud(t_parsing *parser, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		parser->texture_incidator[north]++;
	else if (ft_strncmp(line, "SO", 2) == 0)
		parser->texture_incidator[south]++;
	else if (ft_strncmp(line, "WE", 2) == 0)
		parser->texture_incidator[west]++;
	else if (ft_strncmp(line, "EA", 2) == 0)
		parser->texture_incidator[east]++;
}

static void	is_path_valide(t_parsing *parser, char *line)
{
	char	**path;

	path = ft_split(line + 2, ' ');
	if (path == NULL)
		parser->error_occurred = true;//error message
	if (path[1] != NULL)
		parser->error_occurred = true;//error message
	if (open(path[1], 0) == -1)
		parser->error_occurred = true;//error message
}

