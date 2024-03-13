/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color_indicator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:51:13 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:51:14 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color_indicator(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "F ", 2) == 0
		|| ft_strncmp(parser->line, "C ", 2) == 0)
		return (true);
	return (false);
}
