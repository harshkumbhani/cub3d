#include "cub3d.h"

void	make_structs_accessible(t_game *game, t_parsing *parser)
{
	static t_game		**save_game;
	static t_parsing	**save_parser;

	save_game = get_game_struct();
	save_parser = get_parser_struct();
	*save_game = game;
	*save_parser = parser;
}
