#include "cub3d.h"

static void reopen_file(t_parsing *parser);

void	get_file_content(t_parsing *parser)
{
	char	*tmp_map;
	if (parser->error_occurred == true)
		return ;
	tmp_map = NULL;
	reopen_file(parser);
	parser->line = get_next_line(parser->fd);
	while (parser->line != NULL && parser->error_occurred == false)
	{
		//printf("line %s\n", parser->line);
		save_colors(parser);
		save_texture_path(parser);
		save_map_line(parser, &tmp_map);
		free(parser->line);
		parser->line = get_next_line(parser->fd);
	}
	save_map_in_struct(parser, &tmp_map);
	/*
	int	i = 0;
	while (parser->map[i] != NULL)
	{
		printf("%s\n", parser->map[i]);
		i++;
	}
	*/
	printf("floor %d, %d, %d\n", parser->color[floor][red], parser->color[floor][green], parser->color[floor][blue]);
	printf("ceiling %d, %d, %d\n", parser->color[ceiling][red], parser->color[ceiling][green], parser->color[ceiling][blue]);
	printf("NO %s, SO %s, EA %s, WE %s\n", parser->texture_path[north], parser->texture_path[south], parser->texture_path[east],parser->texture_path[west]);

}

static void reopen_file(t_parsing *parser)
{
	parser->fd = open(parser->av[1], parser->fd);
	if (parser->fd == -1)
		parser_error(INPUT_NO_FILE, parser->av[1], parser);
}
