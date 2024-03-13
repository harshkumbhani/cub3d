/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:51:49 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:51:50 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture(t_parsing *parser)
{
	if ((ft_strncmp(parser->line, "NO ", 3) == 0)
		|| (ft_strncmp(parser->line, "SO ", 3) == 0)
		|| (ft_strncmp(parser->line, "WE ", 3) == 0)
		|| (ft_strncmp(parser->line, "EA ", 3) == 0)
		|| (ft_strncmp(parser->line, "DO ", 3) == 0))
		return (true);
	return (false);
}
