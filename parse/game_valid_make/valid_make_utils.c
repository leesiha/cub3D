/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_make_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:54:08 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/06 17:33:03 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_make(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	map_data_free(char **map_data)
{
	int	idx;

	idx = 0;
	while (map_data[idx] != NULL)
	{
		free(map_data[idx]);
		map_data[idx] = NULL;
	}
	free(map_data);
	map_data = NULL;
}
