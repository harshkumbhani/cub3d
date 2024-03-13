/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:05:56 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 20:09:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////INCLUDE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include "cub3d.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////PARSING//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//INPUT PARSING
void			set_up_parser_struct(t_parsing *parser, int ac, char **av);
void			parse_input(t_parsing *parser);

//SET UP STRUCT
void			set_up_game_struct(t_parsing *parser, t_game *game);
void			find_player_position(t_game *game);
void			set_player_direction(t_game *game,
					t_parsing *parser, char **cpymap);

//FILE PARSING
void			map_syntax_check(t_parsing *parser);
void			file_parsing(t_parsing *parsing);
void			texture_check(t_parsing *parser);
void			replace_newline_with_null_terminator(char *string);
void			color_check(t_parsing *parser);
void			numbers_in_rgb_range_check(t_parsing *parser);
void			detect_garbage(t_parsing *parser);
void			map_line_check(t_parsing *parser);

//INDICATOR FUNCTIONS
void			all_indicators_got_found(t_parsing *parser);
int				is_color_indicator(t_parsing *parser);
int				is_newline(t_parsing *parser);
int				is_texture(t_parsing *parser);
int				is_map_indicator(t_parsing *parser);
int				is_newline(t_parsing *parser);
int				is_player(char *line, t_parsing *parser);

//PARSER ERROR
void			parser_error(char *error_message,
					char *string, t_parsing *parser);

//GET FILE CONTENT
void			get_file_content(t_parsing *parser);
void			save_colors(t_parsing *parser);
void			save_texture_path(t_parsing *parser);
void			save_map_line(t_parsing *parser, char **tmp_map);
void			save_map_in_struct(t_parsing *parser, char **tmp_map);

//VALIDE MAP CHECK
void			valide_map_check(t_parsing *parser);
void			flood_fill_spaces(char **map, int x, int y, t_parsing *parser);
void			compare_zeros(int zero_before,
					int zero_after, t_parsing *parser);
void			check_for_spaces_in_map(char **copied_map, t_parsing *parser);

//MAP MANIPULATION
void			copy_map_with_two_extra_lines(char ***dst_map,
					t_parsing *parser);
void			get_number_of_map_rows(char **map, int *number_rows);
void			add_string_at_top_and_bottom(char **cpy_map, t_parsing *parser);
void			fill_map_with_aligned_lines(char **cpy_map, t_parsing *parser);
void			get_longest_line_in_map(char **map, int *line_len);
void			create_string_of_spaces(t_parsing *parser);
void			enum_map_allocation(t_game *game, t_parsing *parser);
void			fill_enum_map(t_game *game, char **aligned_map);

//FREE STRUCTS
void			free_structs(t_game *game, t_parsing *parser);

//MAKE STRUCTS ASSISSIBLE
void			make_structs_accessible(t_game *game, t_parsing *parser);
t_parsing		**get_parser_struct(void);
t_game			**get_game_struct(void);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////EXECUTION/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// MAIN LOOP

int				launch_game(t_cub3d *cub3d);

// MINIMAP

void			render_line(t_cub3d *mlx, int x1, int y1);
void			render_background(mlx_image_t *image, int height, int width);
void			render_minimap(t_cub3d *mlx);
void			draw_player(t_cub3d *cub3d, int x, int y, int width);
void			update_minimap_player(t_cub3d *cub3d);

//// HOOKS

void			handle_keyhook(mlx_key_data_t keydata, void *param);
bool			collision_with_wall(t_cub3d *mlx, double x, double y);

// INIT

int				init_data(t_cub3d *data);
void			free_execution(t_cub3d *mlx);

// RAYCASTER
void			raycaster(t_cub3d *cub3d);
double			pythagores(double x, double y, t_player *player);
double			normalise_angle(double angle);
int				check_wall(t_cub3d *mlx, double x, double y);
double			vertical_inter(t_cub3d *mlx, double angle);
double			horizontal_inter(t_cub3d *mlx, double angle);

// RENDER

void			render_wall(t_cub3d *mlx, int ray);
uint32_t		color_function(int r, int g, int b, int a);
uint32_t		extract_color(uint8_t *pixels);
void			put_pixel(t_cub3d *mlx, int x, int y, int color);
mlx_texture_t	*get_wall_texture(t_cub3d *cub3d, double ray_angle);
double			calculate_x_offset(t_cub3d *cub3d);

#endif
