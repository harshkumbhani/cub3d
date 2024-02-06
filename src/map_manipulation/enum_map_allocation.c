#include "cub3d.h"

static void	set_y_axis_null(t_map_content **enum_map, int rows);

void	enum_map_allocation(t_game *game, t_parsing *parser)
{
	int		number_of_rows;

	get_number_of_map_rows(parser->input->map, &number_of_rows);
	game->map = (t_map_content **)
		malloc((number_of_rows + 1) * sizeof(t_map_dimensions *));
	if (game->map == NULL)
		return (parser_error(MEMORY_FAILED, NULL, parser));
	set_y_axis_null(game->map, number_of_rows + 1);
}

static void	set_y_axis_null(t_map_content **enum_map, int rows)
{
	int		i;

	i = 0;
	while (i <= rows)
	{
		enum_map[i] = NULL;
		i++;
	}
}
