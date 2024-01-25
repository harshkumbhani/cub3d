#ifndef FUNCTIONS_H
#define FUNCTIONS_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////PARSING//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//INPUT PARSING
void	get_input(t_parsing *parsing, int ac, char **av);
void	pars_input(t_parsing *parser);

//FILE PARSING
void	map_check(t_parsing *parser);
void	file_parsing(t_parsing *parsing);
void	texture_check(t_parsing *parser);
void	replace_newline_with_null_terminator(char *string);
void	color_check(t_parsing *parser);
void	numbers_in_rgb_range_check(t_parsing *parser);
void	detect_garbage(t_parsing *parser);
void	map_line_check(t_parsing *parser);

//INDICATOR FUNCTIONS
void	all_indicators_got_found(t_parsing *parser);
int		is_color_indicator(t_parsing *parser);
int		is_newline(t_parsing *parser);
int		is_texture(t_parsing *parser);
int		is_map_indicator(t_parsing *parser);
int		is_newline(t_parsing *parser);

//PARSER ERROR
void	parser_error(char *error_message, char *string, t_parsing *parser);
#endif
