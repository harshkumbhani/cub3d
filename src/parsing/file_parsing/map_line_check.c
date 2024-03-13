/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:48:06 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:57:01 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	run_while_loop(char c, t_parsing *parser);
static void	is_map_component_check(char c, t_parsing *parser);
static void	player_check(char c, t_parsing *parser);

void	map_line_check(t_parsing *parser)
{
	char	*tmp_line;

	if (parser->error_occurred == true || is_map_indicator(parser) == false)
		return ;
	tmp_line = parser->line;
	while (run_while_loop(*tmp_line, parser) == true)
	{
		is_map_component_check(*tmp_line, parser);
		player_check(*tmp_line, parser);
		tmp_line++;
	}
}

static void	is_map_component_check(char c, t_parsing *parser)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' )
		return ;
	parser_error(GARBAGE_IN_MAP, parser->line, parser);
}

static void	player_check(char c, t_parsing *parser)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		parser->indicator->player++;
	if (parser->indicator->player > 1)
		return (parser_error(GREATER_TWO_PLAYER, parser->line, parser));
}

static int	run_while_loop(char c, t_parsing *parser)
{
	if (c != '\n'
		&& parser->error_occurred == false
		&& c != '\0')
		return (true);
	return (false);
}
