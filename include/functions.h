#ifndef FUNCTIONS_H
#define FUNCTIONS_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////PARSING//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//INPUT PARSING
void	get_input(t_parsing *parsing, int ac, char **av);
void	pars_input(t_parsing *parser);

//FILE PARSING
void	file_parsing(t_parsing *parsing);
void	texture_check(t_parsing *parser);
void	replace_newline_with_null_terminator(char *string);
void	color_check(t_parsing *parser);
void	numbers_in_rgb_range_check(t_parsing *parser);

//INDICATOR FUNCTIONS
int		is_color_indicator(t_parsing *parser);
int		is_texture(char *line);
#endif
