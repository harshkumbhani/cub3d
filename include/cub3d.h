/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:35:18 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/16 12:16:12 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////STANDARD/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include "../libs/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////SELFMADE/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include "color.h"
# include "structures.h"
# include "functions.h"
# include "error_message.h"
# include <math.h>

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
# define ROT_SPEED			0.04
# define PLAYER_SPEED		4

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

# define SEA_AUDIO			"afplay assets/cafe/cafe.wav&"
# define CHOPIN_AUDIO		"afplay assets/chopin/chopin.wav&"
# define CAFE_AUDIO			"afplay assets/sea/sea.wav&"

# define CAFE_CUB			1
# define CHOPIN_CUB			2
# define SEA_CUB			3

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////STANDARD/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif
