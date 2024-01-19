#include "cub3d.h"

static int	is_texture(char *line);
static void	save_texture(char *line, t_parsing *parser);
static void	all_textures_saved_check(t_parsing *parser);
static void	null_terminate_line(char *line);

void	read_texture(t_parsing *parser, char *line, int fd)
{
	if (parser->error_occurred == true || is_texture(line) == false)
		return ;
	while (line != NULL && is_texture(line) == true)
	{
		null_terminate_line(line);
		save_texture(line, parser);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	all_textures_saved_check(parser);
	/*
	printf("north %s\n", parser->input->texture->north);
	printf("south %s\n", parser->input->texture->south);
	printf("west %s\n", parser->input->texture->west);
	printf("east %s\n", parser->input->texture->east);
	*/
}

static int	is_texture(char *line)
{
	if ((ft_strncmp(line, "NO ", 3) == 0)
			|| (ft_strncmp(line, "SO ", 3) == 0)
			|| (ft_strncmp(line, "WE ", 3) == 0)
			|| (ft_strncmp(line, "EA ", 3) == 0))
		return (true);
	return (false);
}

static void	save_texture(char *line, t_parsing *parser)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parser->input->texture->north = ft_strdup(line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parser->input->texture->south = ft_strdup(line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parser->input->texture->west = ft_strdup(line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parser->input->texture->east = ft_strdup(line);
}

static void	all_textures_saved_check(t_parsing *parser)
{
	if (parser->input->texture->north == NULL)
		parser->error_occurred = true;//print_error
	if (parser->input->texture->south == NULL)
		parser->error_occurred = true;//print_error
	if (parser->input->texture->west == NULL)
		parser->error_occurred = true;//print_error
	if (parser->input->texture->east == NULL)
		parser->error_occurred = true;//print_error
}

static void	null_terminate_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	line[i] = '\0';
}
