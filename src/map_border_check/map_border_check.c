#include "cub3d.h"

void	map_border_check(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	int		number_zeros_before;
	int		number_zeros_after;
	char	**copied_map;

	count_zeros_in_map(&number_zeros_before, parser);
	(void) number_zeros_after;
	map_copy_create_square(&copied_map, parser);


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
