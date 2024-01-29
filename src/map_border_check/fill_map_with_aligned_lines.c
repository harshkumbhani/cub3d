#include "cub3d.h"

static void	fill_map_with_extra_space_at_front(t_parsing *parser, char **map);
static void	fill_line_with_spaces_at_back(t_parsing *parser, char **map);

void	fill_map_with_aligned_lines(char **cpy_map, t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	fill_map_with_extra_space_at_front(parser, cpy_map);
	fill_line_with_spaces_at_back(parser, cpy_map);
}

static void	fill_map_with_extra_space_at_front(t_parsing *parser, char **map)
{
	int i;
	int	number_of_rows;

	i = 1;
	get_number_of_map_rows(parser, &number_of_rows);
	while (i < number_of_rows)
	{
		map[i] = ft_strjoin(" ", parser->map[i]);
		if (map[i] == NULL)
			return (parser_error(MEMORY_FAILED, NULL, parser)); //free map
		i++;
	}

}

static void	fill_line_with_spaces_at_back(t_parsing *parser, char **map)
{
	int		i;
	int		str_len;
	int		number_of_rows;
	int		longes_line;

	get_longest_line_in_map(parser->map, &longes_line);
	if (parser->error_occurred == true)
		return ;
	i = 1;
	str_len = 0;
	get_number_of_map_rows(parser, &number_of_rows);
	while(i < number_of_rows)
	{
		str_len = ft_strlen(map[i]);
		map[i] = ft_strjoin_mod(map[i], parser->line  (longes_line - str_len));
		if (map[i] == NULL)
			return (parser_error(MEMORY_FAILED, NULL, parser)); //free map
		i++;
	}
}
