/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:51:41 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:51:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char *line, t_parsing *parser)
{
	if (((ft_strncmp(line, "N", 1) == 0)
			|| (ft_strncmp(line, "S", 1) == 0)
			|| (ft_strncmp(line, "W", 1) == 0)
			|| (ft_strncmp(line, "E", 1) == 0))
		&& is_texture(parser) == false)
		return (true);
	return (false);
}
