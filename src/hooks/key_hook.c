#include "cub3d.h"

void	normalise_angle(double *angle);
void	draw_anotherline(t_image *, int x0, int y0, int x1, int y1);
void	draw_rays(t_image *image);

void	handle_keyhook(mlx_key_data_t keydata, void *param)
{
	t_image	*image;

	image = (t_image *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(image->mlx);
	if (keydata.key == MLX_KEY_UP)
	{
		image->player->instances->x += image->hero->pdx;
		image->player->instances->y += image->hero->pdy;
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		image->player->instances->x -= image->hero->pdx;
		image->player->instances->y -= image->hero->pdy;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		image->angle -= ROTATION_AMOUNT;
		normalise_angle(&image->angle);
		//if (image->angle < 0)
		//	image->angle += 2 * M_PI;
		image->hero->pdx = cos(image->angle) * 5;
		image->hero->pdy = sin(image->angle) * 5;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		image->angle += ROTATION_AMOUNT;
		normalise_angle(&image->angle);
		//if (image->angle > 2 * M_PI)
		//	image->angle -= 2 * M_PI;
		image->hero->pdx = cos(image->angle) * 5;
		image->hero->pdy = sin(image->angle) * 5;
	}
	image->line->x0 = image->player->instances->x + 5;
	image->line->y0 = image->player->instances->y + 5;
	//normalise_angle(&image->angle);
	render_line(image, (image->line->x0 + 5 * image->hero->pdx),
		(image->line->y0 + 5 * image->hero->pdy));
	//draw_rays(image);
}

void	normalise_angle(double *angle)
{
	//*angle = fmod(*angle, M_PI * 2);
	if (*angle < 0)
		*angle += 2 * M_PI;
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
	//printf("player->angle: %2f\n", *angle);
}

void	draw_rays(t_image *image)
{
	int r, mx, my, dof;
	float rx, ry, ra, x0, y0;

	ra = image->hero->pa;
	for (r = 0; r < 1; r++)
	{
		// Horizontal line calculation
		dof = 0;
		float atan = -1/tan(ra);
		if (ra < PI) // ray looking down
		{
			ry = (image->player->instances->y / 50) * 50;
			rx = (image->player->instances->y - ry) * atan + image->player->instances->x;
			y0 = -50;
			x0 = -y0 * atan;
		}
		if (ra > PI) // ray looking up
		{
			ry = (image->player->instances->y / 50) * 50 + 50;
			rx = (image->player->instances->y - ry) * atan + image->player->instances->x;
			y0 = 50;
			x0 = -y0 * atan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = image->player->instances->x;
			ry = image->player->instances->y;
			dof = 8;
		}
		printf("rx: %d ry: %d\n", (int)rx, (int)ry);
		printf("x0: %d y0: %d\n", (int)x0, (int)y0);
		while (dof < 13)
		{
			mx = rx / 50;
			my = ry / 50;
			//mp = my * 13 + mx;
			if (mx >= 0 && mx < 13 && my >= 0 && my < 10)
			{
				if (image->map[mx][my] == 1)
				{
					printf("mx: %d my: %d\n", mx, my);
					dof = 1;
				}
				else
				{
					rx += x0;
					ry += y0;
					dof += 1;
				}
			}
			else
				dof = 13;
		}
	}
	draw_anotherline(image, image->player->instances->x,
		image->player->instances->y, rx, ry);
}

void	draw_anotherline(t_image *player, int x0, int y0, int x1, int y1)
{
	int dx, dy, sx, sy, err, e2, x, y;
	dx = abs(x0 - x1);
	dy = -abs(y0 - y1);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
		x = x0;
	y = y0;
	err = dx + dy;
	while (true)
	{
		mlx_put_pixel(player->window_lin, x, y, 0xFF0000FF);
		if (x == x1 && y == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}
