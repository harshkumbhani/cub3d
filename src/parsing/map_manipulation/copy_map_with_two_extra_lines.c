/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_with_two_extra_lines.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:52:55 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:52:56 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	allocate_map_with_extra_lines(char ***dst_map, t_parsing *parser);
static void	set_map_y_axis_null(char **dst_map, t_parsing *parser);

void	copy_map_with_two_extra_lines(char ***dst_map, t_parsing *parser)
{
	allocate_map_with_extra_lines(dst_map, parser);
	set_map_y_axis_null(*dst_map, parser);
}

static void	allocate_map_with_extra_lines(char ***dst_map, t_parsing *parser)
{
	int	number_of_rows;

	if (parser->error_occurred == true)
		return ;
	get_number_of_map_rows(parser->input->map, &number_of_rows);
	*dst_map = (char **) malloc((number_of_rows + 3) * sizeof(char *));
	if (*dst_map == NULL)
		parser_error(MEMORY_FAILED, NULL, parser);
}

static void	set_map_y_axis_null(char **dst_map, t_parsing *parser)
{
	int		i;
	int		number_of_rows;

	get_number_of_map_rows(parser->input->map, &number_of_rows);
	number_of_rows += 3;
	i = 0;
	while (i < number_of_rows)
	{
		dst_map[i] = NULL;
		i++;
	}
}
