/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:00:03 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 20:00:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

# define RED					"\x01\033[1;31m\x02"
# define DARK_GREEN				"\x01\033[1;32m\x02"
# define GRASS_GREEN			"\x01\033[38;2;0;255;0m\x02"
# define YELLOW					"\x01\033[1;33m\x02"
# define MAGENTA				"\x01\033[1;35m\x02"
# define BLUE					"\x01\033[1;34m\x02"
# define WHITE					"\x01\033[0m\x02"
# define ORANGE					"\x01\033[38;2;255;165;0m\x02"
# define RESET					"\033[0m"
#endif
