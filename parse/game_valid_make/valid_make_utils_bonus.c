/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_make_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:54:08 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		idx++;
	}
	free(map_data);
	map_data = NULL;
}
