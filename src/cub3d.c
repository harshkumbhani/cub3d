/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/05 16:23:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_parsing	parser;
	t_game		game;

	set_up_parser_struct(&parser, ac, av);
	parse_input(&parser);
	file_parsing(&parser);
	get_file_content(&parser);
	valide_map_check(&parser);
	set_up_game_struct(&parser, &game);
	return (0);
}
