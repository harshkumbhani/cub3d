#include "cub3d.h"

static void	convert_numbers_to_int(t_parsing *parser, int *number);
static void	skip_spaces(t_parsing *parser, int *spaces);
static int	number_in_intlong_range(char **string_number);
static void	get_num_in_int_range(char **str_num, int *num, t_parsing *parser);

void	numbers_in_rgb_range_check(t_parsing *parser)
{
	int		number[3];

	convert_numbers_to_int(parser, number);
	if (parser->error_occurred == true)
		return ;
	if (number[red] > 255 || number[green] > 255 || number[blue] > 255
		|| number[red] < 0 || number[green] < 0 || number[blue] < 0)
		parser_error(OUT_OF_RGB_RANGE, parser->line, parser);
}

static void	convert_numbers_to_int(t_parsing *parser, int *number)
{
	char	**string_number;
	int		spaces;

	skip_spaces(parser, &spaces);
	string_number = ft_split((parser->line + spaces), ',');
	if (string_number == NULL)
		parser_error(MEMORY_FAILED, NULL, parser);
	if (count_doupple_arry_quantity(string_number) != 3)
		return (parser_error(IDENTIFICATOR_SET_WRONG, parser->line, parser));
	if (number_in_intlong_range(string_number) == false)
		return (parser_error(OUT_OF_RGB_RANGE, parser->line, parser));
	get_num_in_int_range(string_number, number, parser);
}

static void	skip_spaces(t_parsing *parser, int *spaces)
{
	int	i;

	i = 1;
	while (parser->line[i] == ' ' && parser->line[i] != '\n')
		i++;
	*spaces = i;
}

static int	number_in_intlong_range(char **string_number)
{
	if (ft_strlen(string_number[red]) >= 10
		|| ft_strlen(string_number[green]) >= 10
		|| ft_strlen(string_number[blue]) >= 10)
		return (false);
	return (true);
}

static void	get_num_in_int_range(char **str_num, int *num, t_parsing *parser)
{
	num[red] = ft_strtol(str_num[red]);
	num[green] = ft_strtol(str_num[green]);
	num[blue] = ft_strtol(str_num[blue]);
	if (num[red] > INT_MAX)
		return (parser_error(OUT_OF_RGB_RANGE, parser->line, parser));
	if (num[green] > INT_MAX)
		return (parser_error(OUT_OF_RGB_RANGE, parser->line, parser));
	if (num[blue] > INT_MAX)
		return (parser_error(OUT_OF_RGB_RANGE, parser->line, parser));
}
