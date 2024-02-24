#ifndef CUB3D_H
#define CUB3D_H

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////SELFMADE/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
# include "../MLX42/include/MLX42/MLX42.h"
# include "structures.h"
# include "functions.h"
# include <stdio.h>
# include <stdlib.h>
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
//# define ROTATION_AMOUNT	0.17453
# define LINE_LEN			5
# define FOV				60
# define BLOCK_SIZE			64
# define ROT_SPEED			0.05
# define PLAYER_SPEED		5

# define HORIZONTAL			0
# define VERTICAL			1

# define NORTH				1
# define SOUTH				2
# define EAST				3
# define WEST				4

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////STANDARD/LIBARY////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif