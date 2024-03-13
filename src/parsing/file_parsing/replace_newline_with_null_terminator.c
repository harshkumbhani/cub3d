/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_newline_with_null_terminator.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:48:39 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 19:48:41 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_newline_with_null_terminator(char *string)
{
	if (string == NULL)
		return ;
	while (*string != '\n' && *string != '\0')
		string++;
	*string = '\0';
}
