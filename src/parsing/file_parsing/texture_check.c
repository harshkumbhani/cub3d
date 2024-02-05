#include "cub3d.h"

static void	tell_textrue_got_foud(t_parsing *parser);
static void	is_path_valide(t_parsing *parser);

void	texture_check(t_parsing *parser)
{
	if (parser->error_occurred == true || is_texture(parser) == false)
		return ;
	tell_textrue_got_foud(parser);
	is_path_valide(parser);
}

static void	tell_textrue_got_foud(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "NO", 2) == 0)
		parser->indicator->texture[north]++;
	else if (ft_strncmp(parser->line, "SO", 2) == 0)
		parser->indicator->texture[south]++;
	else if (ft_strncmp(parser->line, "WE", 2) == 0)
		parser->indicator->texture[west]++;
	else if (ft_strncmp(parser->line, "EA", 2) == 0)
		parser->indicator->texture[east]++;
}

static void	is_path_valide(t_parsing *parser)
{
	char	**path;
	int		fd;

	replace_newline_with_null_terminator(parser->line);
	path = ft_split(parser->line + 2, ' ');
	if (path == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	if (count_doupple_arry_quantity(path) != 1)
		return (parser_error(INVALIDE_PATH, parser->line + 2, parser));
	fd = open(path[0], O_RDONLY);
	if (fd == -1)
		parser_error(OPEN_FAILED, path[0], parser);
	free_dubble_array(path);
	close(fd);
}
