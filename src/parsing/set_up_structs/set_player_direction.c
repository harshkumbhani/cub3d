#include "cub3d.h"

static void	scan_line_for_player_direction(char *line, t_game *game);
static bool	detect_player_direction(t_game *game, char content);

void	set_player_direction(t_game *game, t_parsing *parser, char **cpymap)
{
	int	i;

	i = 0;
	if (parser->error_occurred == true)
		return ;
	while (cpymap[i] != NULL)
	{
		scan_line_for_player_direction(cpymap[i], game);
		i++;
	}
}

static void	scan_line_for_player_direction(char *line, t_game *game)
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

static bool	detect_player_direction(t_game *game, char content)
{
	if (content == 'N')
	{
		game->direction_facing = north;
		return (true);
	}
	else if (content == 'S')
	{
		game->direction_facing = south;
		return (true);
	}
	else if (content == 'E')
	{
		game->direction_facing = east;
		return (true);
	}
	else if (content == 'W')
	{
		game->direction_facing = west;
		return (true);
	}
	return (false);
}
