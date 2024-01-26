#include "cub3d.h"

void get_longest_line(size_t *longest_line, char **map_copy);

void	create_square_map_filled_whit_space(char **map_copy, t_parsing *parser)
{
	size_t	longest_line;

	get_longest_line(&longest_line, map_copy);
	
}

void	get_longest_line(size_t *longest_line, char **map_copy)
{
	int		i;

	i = 0;
	*longest_line = 0;
	while (map_copy[i] != NULL)
	{
		if (ft_strlen(map_copy[i]) > *longest_line)
			*longest_line = ft_strlen(map_copy[i]);
		i++;
	}
}

void	add_space_line_at_top_and_bottom(t_parsing )
