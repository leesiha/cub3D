/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_map_creat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:33:45 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/26 17:53:39 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_size_find(t_map *map_info, char **converted_str)
{
	int	row;
	int	col;
	int	idx;

	row = 6;
	col = 0;
	while (converted_str[row] != NULL)
	{
		idx = 0;
		while (converted_str[row][idx] != '\0')
			idx++;
		if (col < idx)
			col = idx;
		row++;
	}
	map_info->h = row - 6;
	map_info->w = col;
	map_info->p_row = 7;
	map_info->p_col = 7;
}

void	map_init(t_map *map_info)
{
	int	idx;

	idx = 0;
	map_info->map = malloc(sizeof(char *) * (map_info->h + 1));
	if (map_info->map == NULL)
		error_exit("malloc failed");
	while (idx < map_info->h)
	{
		map_info->map[idx] = malloc(map_info->w + 1);
		if (map_info->map[idx] == NULL)
			error_exit("malloc failed");
		idx++;
	}
	map_info->map[idx] = NULL;
}

void	map_make(t_map *map_info, char **converted_str)
{
	int	str_row;
	int	map_row;
	int	col;

	str_row = 6;
	map_row = 0;
	while (map_row < map_info->h)
	{
		col = 0;
		while (col < map_info->w)
		{
			if (converted_str[str_row][col] != '\0')
				map_info->map[map_row][col] = converted_str[str_row][col];
			else
				map_info->map[map_row][col] = ' ';
			col++;
		}
		map_info->map[map_row][col] = '\0';
		str_row++;
		map_row++;
	}
}

void	game_map_creat(t_map *map_info, char **converted_str)
{
	map_size_find(map_info, converted_str);
	map_init(map_info);
	map_make(map_info, converted_str);
}
