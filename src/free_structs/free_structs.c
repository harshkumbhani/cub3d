#include "cub3d.h"

static void	free_game_struct(t_game *game);
static void	free_parser_struct(t_parsing *parser);
static void	free_directions(t_directions *direction);

void	free_structs(t_game *game, t_parsing *parser)
{
	free_game_struct(game);
	free_parser_struct(parser);
}

static void	free_game_struct(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
}

static void	free_parser_struct(t_parsing *parser)
{
	if (parser->line != NULL)
		free(parser->line);
	free_dubble_array(parser->input->map);
	free_directions(parser->input->texture);
}

static void	free_directions(t_directions *direction)
{
	free(direction->north);
	free(direction->south);
	free(direction->east);
	free(direction->west);
	free(direction->door);
}
