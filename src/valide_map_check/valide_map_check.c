#include "cub3d.h"

void	valide_map_check(t_parsing *parser)
{
	char	**copied_map;

	if (parser->error_occurred == true)
		return ;
	copy_map_with_two_extra_lines(&copied_map, parser);
	create_string_of_spaces(parser);
	add_string_at_top_and_bottom(copied_map, parser);
	fill_map_with_aligned_lines(copied_map, parser);
	flood_fill_spaces(copied_map, 0, 0, parser);
	check_for_spaces_in_map(copied_map, parser);
	free_dubble_array(copied_map);
}
/*
   int	i;
   int	rows;
   i = 0;
   get_number_of_map_rows(parser->map, &rows);
   rows += 2;
   while(i < rows)
   {
   if (i > 10)
   printf("%d [%s]\n", i, copied_map[i]);
   if (i < 10)
   printf("%d  [%s]\n", i, copied_map[i]);
   i++;
   }
   */
/*
   double_array_len = count_doupple_arry_quantity(parser->map);
   printf("array quantity %d\n", double_array_len);
   printf("str len %zu\n", ft_strlen(parser->map[4]));
   tmp_map = ft_strjoin("5", parser->map[4]);
   tmp_map = ft_strjoin(tmp_map, "5");
   printf("%s\n", tmp_map);
   printf("str len %zu\n", ft_strlen(tmp_map));
   */
