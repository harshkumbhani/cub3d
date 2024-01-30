#include "cub3d.h"

void	flood_fill_spaces(char **map, int x, int y)
{
	int		rows;
	int		str_len;

	get_number_of_map_rows(map, &rows);
	str_len = (int) ft_strlen(map[0]);
	if (x < 0 || y < 0 || y >= rows || x >= str_len
		|| map[y][x] == 'F' || map[y][x] == '1')
		return ;
	map[y][x] = 'F';
	flood_fill_spaces(map, x - 1, y);
	flood_fill_spaces(map, x + 1, y);
	flood_fill_spaces(map, x, y - 1);
	flood_fill_spaces(map, x, y + 1);
}
