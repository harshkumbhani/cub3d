/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:58:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:58:48 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_game_struct(t_game *game);
static void	free_parser_struct(t_parsing *parser);
static void	free_directions(t_directions *direction);

void	free_structs(t_game *game, t_parsing *parser)
{
	free_parser_struct(parser);
	free_game_struct(game);
}

static void	free_game_struct(t_game *game)
{
	int	i;

	if (game->map == NULL)
		return ;
	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
}

static void	free_parser_struct(t_parsing *parser)
{
	if (parser->line != NULL)
		free(parser->line);
	if (parser->input->map != NULL)
		free_dubble_array(parser->input->map);
	free_directions(parser->input->texture);
}

static void	free_directions(t_directions *direction)
{
	ft_free_string_save(&direction->north);
	ft_free_string_save(&direction->south);
	ft_free_string_save(&direction->east);
	ft_free_string_save(&direction->west);
}
