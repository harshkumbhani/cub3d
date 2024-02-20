#ifndef FUNCTIONS_H
#define FUNCTIONS_H

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////INPUT/PARSING///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// MINIMAP

void	render_line(t_line *line, int x1, int y1);
void	render_background(mlx_image_t *image);
void	render_block(mlx_image_t *image, int x_pos, int y_pos);
void	render_map(t_image *image, int arr[10][13]);
void	render_player(t_image *player, int x_pos, int y_pos);

// HOOKS

void	handle_keyhook(mlx_key_data_t keydata, void *param);

#endif
