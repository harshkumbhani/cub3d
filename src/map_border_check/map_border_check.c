#include "cub3d.h"

void	map_border_check(t_parsing *parser)
{
	int		number_zeros_before;
	int		number_zeros_after;
	char	**map_copy;

	count_zeros_in_map(&number_zeros_before, parser);
	map_copy = copy_dubble_array(parser->map);

	/*
	double_array_len = count_doupple_arry_quantity(parser->map);
	printf("array quantity %d\n", double_array_len);
	printf("str len %zu\n", ft_strlen(parser->map[4]));
	tmp_map = ft_strjoin("5", parser->map[4]);
	tmp_map = ft_strjoin(tmp_map, "5");
	printf("%s\n", tmp_map);
	printf("str len %zu\n", ft_strlen(tmp_map));
	*/
}
