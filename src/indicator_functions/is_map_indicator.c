#include "cub3d.h"

static int	is_wall(char *line);
static int	is_space(char *line, t_parsing *parser);
static int	is_empty_space(t_parsing *parser);

int	is_map_indicator(t_parsing *parser)
{
	if (is_wall(parser->line) == true
		|| is_player(parser->line, parser) == true
		|| is_space(parser->line, parser) == true
		|| is_ammo(parser->line) == true
		|| is_door(parser->line) == true
		|| is_enemy(parser->line) == true
		|| is_exit(parser->line) == true)
		return (true);
	return (false);

}

static int	is_wall(char *line)
{
	if (ft_strncmp(line, "1", 1) == 0)
		return (true);
	return (false);
}

static int	is_space(char *line, t_parsing *parser)
{
	if (ft_strncmp(line, "0", 1) == 0)
		return (true);
	else if (is_empty_space(parser) == true)
		return (true);
	return (false);
}

static int	is_empty_space(t_parsing *parser)
{
	int	spaces;

	if (ft_strncmp(parser->line, " ", 1) != 0)
		return (false);
	spaces = 0;
	while (parser->line[spaces] == ' ')
		spaces++;
	if (ft_strncmp(parser->line + spaces, "0", 1) == 0
		|| ft_strncmp(parser->line + spaces, "\n", 1) == 0
		|| is_wall(parser->line + spaces) == true
		|| is_player((parser->line + spaces), parser) == true
		|| is_ammo(parser->line + spaces) == true
		|| is_door(parser->line + spaces) == true
		|| is_enemy(parser->line + spaces) == true
		|| is_exit(parser->line + spaces) == true)
		return (true);
	return (false);
}
