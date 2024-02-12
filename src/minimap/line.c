#include "cub3d.h"

static void	calculate_line_endpoint(t_image *player);
static void	draw_line(t_image *player);

void	render_line(t_image *player)
{
	render_background(player->window_lin);
	calculate_line_endpoint(player);
	draw_line(player);
}

static void	calculate_line_endpoint(t_image *player)
{
	player->line->x1 = (player->line->x0 + 5 * player->hero->pdx);
	player->line->y1 = (player->line->y0 + 5 * player->hero->pdy);
	if (player->line->y1 < 0)
		player->line->y1 = 0;
	else if (player->line->y1 > 500)
		player->line->y1 = 500;
	if (player->line->x1 < 0)
		player->line->x1 = 0;
	else if (player->line->x1 > 50 * 13)
		player->line->x1 = 50 * 13;
	player->line->dx = abs(player->line->x0 - player->line->x1);
	player->line->dy = -abs(player->line->y0 - player->line->y1);
	if (player->line->x0 < player->line->x1)
		player->line->sx = 1;
	else
		player->line->sx = -1;
	if (player->line->y0 < player->line->y1)
		player->line->sy = 1;
	else
		player->line->sy = -1;
}

static void	draw_line(t_image *player)
{
	int	err;
	int	e2;
	int	x;
	int	y;

	x = player->line->x0;
	y = player->line->y0;
	err = player->line->dx + player->line->dy;
	while (true)
	{
		mlx_put_pixel(player->window_lin, x, y, 0xFFCC33FF);
		if (x == player->line->x1 && y == player->line->y1)
			break ;
		e2 = 2 * err;
		if (e2 >= player->line->dy)
		{
			err += player->line->dy;
			x += player->line->sx;
		}
		if (e2 <= player->line->dx)
		{
			err += player->line->dx;
			y += player->line->sy;
		}
	}
}
