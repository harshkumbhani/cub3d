/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_of_spaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:53:06 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:53:07 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_line_with_spaces(t_parsing *parser, int size);

void	create_string_of_spaces(t_parsing *parser)
{
	int		number_of_rows;
	int		longest_line;

	if (parser->error_occurred == true)
		return ;
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	get_longest_line_in_map(parser->input->map, &longest_line);
	parser->line = (char *) malloc((longest_line + 3) * sizeof(char));
	if (parser->line == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	parser->line[longest_line + 2] = '\0';
	fill_line_with_spaces(parser, longest_line + 2);
}

static void	fill_line_with_spaces(t_parsing *parser, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		parser->line[i] = ' ';
		i++;
	}
}
