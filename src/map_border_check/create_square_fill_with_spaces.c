#include "cub3d.h"

void	copy_each_line_make_same_length(char **cpy_map, t_parsing *parser);
static void	add_space_in_front_of_line(char **cpy_map, t_parsing *parser);
void	test(t_parsing *parser);

void	create_square_fill_with_spaces(char **cpy_map, t_parsing *parser)
{
	char	*space_line;
	int		longest_line;

	get_longest_line_in_map(parser->map, &longest_line);
	space_line = ft_calloc(longest_line, sizeof(char));
	if (space_line == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	fill_line_with_spaces(space_line, longest_line - 1);
	add_space_line_at_top_and_bottom(&cpy_map, space_line, longest_line);
	test(parser);
	copy_each_line_make_same_length(cpy_map, parser);
	/*
	while (*cpy_map != NULL)
	{
		ft_printf("map: [%s]\n", *cpy_map);
		ft_printf("map: [%s]\n", cpy_map[longest_line]);
		cpy_map++;
	}
	*/
	(void) cpy_map;
}

void	test(t_parsing *parser)
{
	printf("in file map: %s \n", parser->map[8]);
}
void	copy_each_line_make_same_length(char **cpy_map, t_parsing *parser)
{
	add_space_in_front_of_line(cpy_map, parser);
}

static void	add_space_in_front_of_line(char **cpy_map, t_parsing *parser)
{
	int	i;

	 i = 1;

	 //printf("map: %s i: %d\n", parser->map[i], i);
 	 (void) cpy_map;
	 (void) parser;
	 (void) i;
	 /*
	while (parser->map[i] != NULL)
	{
		free(cpy_map[i]);
		cpy_map[i] = ft_strjoin(" ", parser->map[i]);
		i++;
	}
	*/
}
