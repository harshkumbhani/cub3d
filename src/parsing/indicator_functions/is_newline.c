/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_newline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:51:33 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:51:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_newline(t_parsing *parser)
{
	if (ft_strncmp(parser->line, "\n", 1) == 0)
		return (true);
	return (false);
}