/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:49:08 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:49:10 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free_dubble_array(string_number);
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
		parser->input->ground->red = ft_atoi(str_number[red]);
		parser->input->ground->green = ft_atoi(str_number[green]);
		parser->input->ground->blue = ft_atoi(str_number[blue]);
	}
	else if (ft_strncmp(parser->line, "C", 1) == 0)
	{
		parser->input->ceiling->red = ft_atoi(str_number[red]);
		parser->input->ceiling->green = ft_atoi(str_number[green]);
		parser->input->ceiling->blue = ft_atoi(str_number[blue]);
	}
}
