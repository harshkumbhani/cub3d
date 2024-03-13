/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_with_aligned_lines.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:55:03 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:55:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;
	int	number_of_rows;

	i = 1;
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	number_of_rows += 1;
	while (i < number_of_rows)
	{
		map[i] = ft_strjoin(" ", parser->input->map[i - 1]);
		if (map[i] == NULL)
			return (parser_error(MEMORY_FAILED, NULL, parser));
		i++;
	}
}

static void	fill_line_with_spaces_at_back(t_parsing *parser, char **map)
{
	int		i;
	int		str_len;
	int		number_of_rows;
	int		longes_line;

	if (parser->error_occurred == true)
		return ;
	i = 1;
	get_longest_line_in_map(parser->input->map, &longes_line);
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	number_of_rows += 2;
	while (i < number_of_rows)
	{
		str_len = ft_strlen(map[i]);
		map[i] = ft_strjoin_mod(map[i], parser->line + (str_len));
		if (map[i] == NULL)
			return (parser_error(MEMORY_FAILED, NULL, parser));
		i++;
	}
}
