/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:47:54 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:47:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	open_file(t_parsing *parser);
static void	get_line(t_parsing *parser);
static void	found_player_check(t_parsing *parser);

void	file_parsing(t_parsing *parsing)
{
	if (parsing->error_occurred == true)
		return ;
	open_file(parsing);
	get_line(parsing);
	while (parsing->line != NULL && parsing->error_occurred == false)
	{
		texture_check(parsing);
		color_check(parsing);
		detect_garbage(parsing);
		map_syntax_check(parsing);
		free(parsing->line);
		get_line(parsing);
	}
	found_player_check(parsing);
	parsing->line = NULL;
	close(parsing->fd);
}

static void	open_file(t_parsing *parser)
{
	parser->fd = 0;
	parser->fd = open(parser->input->av[1], O_RDONLY);
	if (parser->fd == -1)
		parser_error(INPUT_NO_FILE, parser->input->av[1], parser);
}

static void	get_line(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	parser->line = get_next_line(parser->fd);
}

static void	found_player_check(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	if (parser->indicator->player != 1)
		parser_error(NO_PLAYER_FOUND, NULL, parser);
}
