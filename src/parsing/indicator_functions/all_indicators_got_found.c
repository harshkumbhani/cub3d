/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_indicators_got_found.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:50:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:50:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_color_indicators_found(t_parsing *parsing);
static int	texture_indicators_got_found(t_parsing *parsing);

void	all_indicators_got_found(t_parsing *parser)
{
	if (all_color_indicators_found(parser) == false
		|| texture_indicators_got_found(parser) == false)
		parser_error(NOT_ALL_INDICATORS, NULL, parser);
}

static int	all_color_indicators_found(t_parsing *parsing)
{
	if ((parsing->indicator->color[ceiling] != 1)
		|| (parsing->indicator->color[ground] != 1))
		return (false);
	return (true);
}

static int	texture_indicators_got_found(t_parsing *parsing)
{
	if ((parsing->indicator->texture[north] != 1)
		|| (parsing->indicator->texture[south] != 1)
		|| (parsing->indicator->texture[west] != 1)
		|| (parsing->indicator->texture[east] != 1))
		return (false);
	return (true);
}
