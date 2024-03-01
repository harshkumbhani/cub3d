/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
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
	free_structs(&game, &parser);
	system("leaks cub3d");
	return (0);
}
