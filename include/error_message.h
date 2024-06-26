/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:59:32 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 20:02:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

//PARSER ERROR
# define WRONG_AMOUNT_INPUT		"Wrong amount of input parameters found"
# define INPUT_NO_FILE			"Inputed file cannot be opened: "
# define OPEN_FAILED				"File can't be opend: "
# define MEMORY_FAILED			"Memory allocation failed"
# define NOT_CUB_FILE			"Inputed file isn't format .cub: "
# define INVALIDE_PATH			"Path in .cub file is invalide: "
# define OUT_OF_RGB_RANGE		"Color indicator number isn't in rgb range: "
# define GARBAGE_FOUND			"Non valide char in .cub file found: "
# define NEWLINE_IN_MAP			"Newline was found in map"
# define NOT_ALL_INDICATORS		"Not all indicators found before map started"
# define IDENTIFICATOR_SET_WRONG	"Identificator is set false: "
# define GARBAGE_IN_MAP			"False char found in map: "
# define GREATER_TWO_PLAYER		"More than one player found: "
# define NO_PLAYER_FOUND			"No player found in map, set N, S, W or E"
# define MAP_IS_NOT_CLOSED		"Inputed map isn't closed by 1"
# define PLAYER_OUT_OF_MAP		"Player found outside of map: "
# define DOOR_OUT_OF_MAP			"Door found outside of map: "
# define AMMO_OUT_OF_MAP			"Enemy found outside of map: "
# define SPACE_IN_MAP			"Found space in map: "
# define FATAL_MLX_INIT			"mlx init failed :("
# define FATAL_TEX_LOAD			"mlx load png failed :("
# define FATAL_NEW_IMAGE			"mlx new image failed :("

#endif
