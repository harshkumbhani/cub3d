#include "cub3d.h"

void	parser_error(char *error_message, char *string, t_parsing *parser)
{
	parser->error_occurred = true;
	if (string == NULL)
	 printf("%s%s%s\n", RED, error_message, RESET);
	else
	{
		replace_newline_with_null_terminator(string);
		printf("%s%s%s%s%s\n", RED, error_message, ORANGE, string, RESET);
	}
}
