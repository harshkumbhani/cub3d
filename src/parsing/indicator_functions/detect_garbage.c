/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_garbage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:50:30 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:50:31 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	file_content(t_parsing *parser);

void	detect_garbage(t_parsing *parser)
{
	if (file_content(parser) == true)
		return ;
	parser_error(GARBAGE_FOUND, parser->line, parser);
}

static int	file_content(t_parsing *parser)
{
	if (is_map_indicator(parser) == true
		|| is_newline(parser) == true
		|| is_texture(parser) == true
		|| is_color_indicator(parser) == true)
		return (true);
	return (false);
}
