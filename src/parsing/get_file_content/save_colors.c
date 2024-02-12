#include "cub3d.h"

static void	get_rgb_string_as_int(t_parsing *parser);
static void	skip_spaces(int *spaces, t_parsing *parser);
static void	fill_color_struct(t_parsing *parser, char **str_number);

void	save_colors(t_parsing *parser)
{
	if (is_color_indicator(parser) == false)
		return ;
	get_rgb_string_as_int(parser);
}

static void	get_rgb_string_as_int(t_parsing *parser)
{
	char	**string_number;
	int		spaces;

	skip_spaces(&spaces, parser);
	string_number = ft_split(parser->line + spaces, ',');
	if (string_number == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	fill_color_struct(parser, string_number);
}

static void	skip_spaces(int *spaces, t_parsing *parser)
{
	int		i;

	i = 1;
	while (parser->line[i] == ' ' && parser->line[i] != '\n')
		i++;
	*spaces = i;
}

static void	fill_color_struct(t_parsing *parser, char **str_number)
{
	if (ft_strncmp(parser->line, "F", 1) == 0)
	{
		parser->input->floor->red = ft_atoi(str_number[red]);
		parser->input->floor->green = ft_atoi(str_number[green]);
		parser->input->floor->blue = ft_atoi(str_number[blue]);
	}
	else if (ft_strncmp(parser->line, "C", 1) == 0)
	{
		parser->input->ceiling->red = ft_atoi(str_number[red]);
		parser->input->ceiling->green = ft_atoi(str_number[green]);
		parser->input->ceiling->blue = ft_atoi(str_number[blue]);
	}
}
