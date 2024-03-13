#include "cub3d.h"

t_game	**get_game_struct(void)
{
	static t_game *game;

	return (&game);
}
