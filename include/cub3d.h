/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:35:18 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/13 20:36:13 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////STANDARD/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////SELFMADE/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include "color.h"
# include "structures.h"
# include "functions.h"
# include "error_message.h"
# include "math.h"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////SELFMADE/DEFINES///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# ifndef WIDTH
#  define WIDTH 1500
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# define PI					3.1415926535
# define LINE_LEN			25
# define FOV				60
# define BLOCK_SIZE			64
# define ROT_SPEED			0.08
# define PLAYER_SPEED		10

# define HORIZONTAL			0
# define VERTICAL			1

# define NORTH				0
# define SOUTH				1
# define EAST				2
# define WEST				3

# define MINIMAP_SCALE		0.1
# define MINIMAP_SIZE_X		300
# define MINIMAP_SIZE_Y		250
# define MINIMAP_POS_X		20
# define MINIMAP_POS_Y		20

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////STANDARD/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif