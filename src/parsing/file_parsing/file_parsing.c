#include "cub3d.h"

static void	open_file(t_parsing *parser);
static void	get_line(t_parsing *parser);

void	file_parsing(t_parsing *parsing)
{
	if (parsing->error_occurred == true)
		return ;
	open_file(parsing);
	get_line(parsing);
	while(parsing->line != NULL && parsing->error_occurred == false)
	{
		texture_check(parsing);
		color_check(parsing);
		detect_garbage(parsing);
		map_syntax_check(parsing);
		free(parsing->line);
		get_line(parsing);
	}
	/*
	printf("color indicator floor: %d, ceiling: %d\n",
			parsing->color_indicator[floor], parsing->color_indicator[ceiling]);
	printf("texture indicator NO: %d, SO: %d, EA: %d, WE: %d\n",
			parsing->texture_indicator[north], parsing->texture_indicator[south]
			, parsing->texture_indicator[east], parsing->texture_indicator[west]);
	*/
}

static void	open_file(t_parsing *parser)
{
	parser->fd = 0;
	parser->fd = open(parser->av[1], parser->fd);
	if (parser->fd == -1)
		parser_error(INPUT_NO_FILE, parser->av[1], parser);

}

static void	get_line(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	parser->line = get_next_line(parser->fd);
}
