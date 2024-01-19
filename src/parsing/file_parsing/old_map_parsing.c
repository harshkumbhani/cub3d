#include "cub3d.h"

static void	open_file(t_parsing *parser, int *fd);
static void	allocate_input_struct(t_parsing *parser);

void	map_parsing(t_parsing *parser)
{
	int		fd;
	char	*line;

	if (parser->error_occurred == true)
		return ;
	open_file(parser, &fd);
	allocate_input_struct(parser);
	line = get_next_line(fd);
	while (line != NULL && parser->error_occurred == false)
	{
		read_texture(parser, line, fd);
		free(line);
		line = get_next_line(fd);
	}
}

static void	open_file(t_parsing *parser, int *fd)
{
	*fd = 0;
	*fd = open(parser->av[1], *fd);
	if (*fd == -1)
	{
		//print_error();
		return ;
	}
}

static void	allocate_input_struct(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	parser->input = ft_calloc(1, sizeof(t_parsing));
	if (parser == NULL)
		return ;//print_error
	parser->input->floor = ft_calloc(1, sizeof(t_parsing));
	if (parser->input->floor == NULL)
		return ;//print_error
	parser->input->ceiling = ft_calloc(1, sizeof(t_parsing));
	if (parser->input->ceiling == NULL)
		return ;//print_error
	parser->input->texture = ft_calloc(1, sizeof(t_parsing));
	if (parser->input->texture == NULL)
		return ;//print_error
}
