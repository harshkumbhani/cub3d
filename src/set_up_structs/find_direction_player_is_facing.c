#include "cub3d.h"

static void	scan_line_for_player_direction(t_map_content *line, t_game *game);
static bool	detect_player_direction(t_game *game, t_map_content content);

void	find_direction_player_is_facing(t_game *game, t_parsing *parser)
{
	int	i;

	i = 0;
	if (parser->error_occurred == true)
		return ;
	while (game->map[i] != NULL)
	{
		scan_line_for_player_direction(game->map[i], game);
		i++;
	}
}

static void	scan_line_for_player_direction(t_map_content *line, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_dimensions[width])
	{
		if (detect_player_direction(game, line[i]) == true)
			return ;
		i++;
	}
}

static bool	detect_player_direction(t_game *game, t_map_content content)
{
	if (content == north)
	{
		game->direction_facing = north;
		return (true);
	}
	else if (content == south)
	{
		game->direction_facing = south;
		return (true);
	}
	else if (content == east)
	{
		game->direction_facing = east;
		return (true);
	}
	else if (content == west)
	{
		game->direction_facing = west;
		return (true);
	}
	return (false);
}
