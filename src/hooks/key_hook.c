#include "cub3d.h"

void	handle_keyhook(mlx_key_data_t keydata, void *param)
{
	t_image	*image;

	image = (t_image *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(image->mlx);
	if (keydata.key == MLX_KEY_UP)
	{
		image->player->instances->y += (4 * sin(image->angle));
		image->player->instances->x += (4 * cos(image->angle));
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		image->player->instances->y -= (4 * sin(image->angle));
		image->player->instances->x -= (4 * cos(image->angle));
	}
	if (keydata.key == MLX_KEY_RIGHT)
		image->angle += ROTATION_AMOUNT;
	if (keydata.key == MLX_KEY_LEFT)
		image->angle -= ROTATION_AMOUNT;
	image->line->y0 = image->player->instances->y + 5;
	image->line->x0 = image->player->instances->x + 5;
	render_line(image);
}
