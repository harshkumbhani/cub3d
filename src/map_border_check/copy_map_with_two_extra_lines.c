#include "cub3d.h"

static void allocate_map_with_extra_lines(char ***dst_map, t_parsing *parser);
static void	set_map_y_axis_null(char **dst_map, t_parsing *parser);

void	copy_map_with_two_extra_lines(char ***dst_map, t_parsing *parser)
{
	allocate_map_with_extra_lines(dst_map, parser);
	set_map_y_axis_null(*dst_map, parser);
}

static void allocate_map_with_extra_lines(char ***dst_map, t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	int	number_of_rows;
	
	get_number_of_map_rows(parser, &number_of_rows);
	*dst_map = (char **) malloc((number_of_rows + 1) * sizeof(char *));
	if (*dst_map == NULL)
		parser_error(MEMORY_FAILED, NULL, parser);
}

static void	set_map_y_axis_null(char **dst_map, t_parsing *parser)
{
	int		i;
	int		number_of_rows;

	get_number_of_map_rows(parser, &number_of_rows);
	number_of_rows += 1;
	i = 0;
	while (i < number_of_rows)
	{
		dst_map[i] = NULL;
		i++;
	}
}
