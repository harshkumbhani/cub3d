/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_map_rows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:54:52 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:54:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_number_of_map_rows(char **map, int *number_rows)
{
	if (map == NULL || *map == NULL)
	{
		*number_rows = 0;
		return ;
	}
	(*number_rows) = count_doupple_arry_quantity(map);
}
