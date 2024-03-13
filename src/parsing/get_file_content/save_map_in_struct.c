/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_in_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:49:24 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:49:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map_in_struct(t_parsing *parser, char **tmp_map)
{
	if (parser->error_occurred == true)
		return (free(tmp_map));
	parser->input->map = ft_split(*tmp_map, '\1');
	if (parser->input->map == NULL)
		parser_error(MEMORY_FAILED, NULL, parser);
	free(*tmp_map);
	tmp_map = NULL;
}
