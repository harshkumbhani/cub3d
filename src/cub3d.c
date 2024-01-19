/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/01/19 10:15:41 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	int x = -1;
	int	y = -1;

	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Window", true);
	mlx_image_t	*image;

	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, image, x, y);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			//printf("x: %d y: %d\n", x, );
			if (y == (int)(((float)HEIGHT / WIDTH) * x)
				|| y == (int)(HEIGHT - (((float)HEIGHT / WIDTH) * x)))
				mlx_put_pixel(image, x, y, 0xFF0000FF);
		}
	}
	//mlx_put_pixel(image, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
