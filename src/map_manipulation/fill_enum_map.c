#include "cub3d.h"

static void	assign_char_to_enum(char c, t_map_content *enum_map, int x);
static void	scan_map_line(t_map_content *enum_map, char *aligned_map);
static void	add_lines_to_enum_map(t_map_content **enum_map, char **aligned_map);
static void	fill_map_with_enums(t_map_content **enum_map, char **aligned_map);

void	fill_enum_map(t_game *game, char **aligned_map)
{
	add_lines_to_enum_map(game->map, aligned_map);
	fill_map_with_enums(game->map, aligned_map);
}

static void	add_lines_to_enum_map(t_map_content **enum_map, char **aligned_map)
{
	int		number_or_rows;
	int		str_len;
	int		y;

	str_len = (int) ft_strlen(aligned_map[0]);
	get_number_of_map_rows(aligned_map, &number_or_rows);
	number_or_rows -= 2;
	y = 0;
	while (y <= number_or_rows)
	{
		enum_map[y] = (t_map_content *) malloc(str_len * sizeof(t_map_content));
		y++;
	}
}

static void	fill_map_with_enums(t_map_content **enum_map, char **aligned_map)
{
	int		y;
	int		number_or_rows;

	get_number_of_map_rows(aligned_map, &number_or_rows);
	number_or_rows -= 2;
	y = 1;
	while (y <= number_or_rows)
	{
		printf("\n");
		scan_map_line(enum_map[y - 1], aligned_map[y]);
		y++;
	}
}

static void	scan_map_line(t_map_content *enum_map, char *aligned_map)
{
	int		x;

	x = 0;
	while (aligned_map[x] != '\0')
	{
		assign_char_to_enum((aligned_map[x]), enum_map, x);
		printf("%d", enum_map[x]);
		x++;
	}
}

static void	assign_char_to_enum(char c, t_map_content *enum_map, int x)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		enum_map[x] = player;
	if (c == '1')
		enum_map[x] = wall;
	if (c == 'D')
		enum_map[x] = door;
	if (c == ' ')
		enum_map[x] = space;
	if (c == '0')
		enum_map[x] = zero;
	if (c == 'X')
		enum_map[x] = zero;
	if (c == 'R')
		enum_map[x] = ronan;
	if (c == 'B')
		enum_map[x] = nebula;
	if (c == 'K')
		enum_map[x] = kango;
}
