/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:50:09 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:50:10 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reopen_file(t_parsing *parser);

void	get_file_content(t_parsing *parser)
{
	char	*tmp_map;

	if (parser->error_occurred == true)
		return ;
	tmp_map = NULL;
	reopen_file(parser);
	parser->line = get_next_line(parser->fd);
	while (parser->line != NULL && parser->error_occurred == false)
	{
		save_colors(parser);
		save_texture_path(parser);
		save_map_line(parser, &tmp_map);
		free(parser->line);
		parser->line = get_next_line(parser->fd);
	}
	save_map_in_struct(parser, &tmp_map);
	close(parser->fd);
}

static void	reopen_file(t_parsing *parser)
{
	parser->fd = open(parser->input->av[1], O_RDONLY);
	if (parser->fd == -1)
		parser_error(INPUT_NO_FILE, NULL, parser);
}
