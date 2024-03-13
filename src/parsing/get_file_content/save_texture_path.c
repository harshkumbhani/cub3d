/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:49:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:49:47 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_struct(t_parsing *parser, char **path);
static void	save_path_in_struct(t_parsing *parser, char *path);

void	save_texture_path(t_parsing *parser)
{
	char	*path;

	if (is_texture(parser) == false || parser->error_occurred == true)
		return ;
	path = NULL;
	get_struct(parser, &path);
	save_path_in_struct(parser, path);
}

static void	get_struct(t_parsing *parser, char **path)
{
	char	**tmp_path;

	replace_newline_with_null_terminator(parser->line);
	tmp_path = ft_split(parser->line + 2, ' ');
	if (tmp_path[0] == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	*path = ft_strdup(tmp_path[0]);
	free_dubble_array(tmp_path);
}

static void	save_path_in_struct(t_parsing *parser, char *path)
{
	if (ft_strncmp(parser->line, "NO", 2) == 0)
		parser->input->texture->north = path;
	if (ft_strncmp(parser->line, "SO", 2) == 0)
		parser->input->texture->south = path;
	if (ft_strncmp(parser->line, "EA", 2) == 0)
		parser->input->texture->east = path;
	if (ft_strncmp(parser->line, "WE", 2) == 0)
		parser->input->texture->west = path;
}
