/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info_creat_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:59:40 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:38:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_char_and_size_check(t_map *map_info, char **map_data, \
								int row, int col)
{
	int	p_cnt;

	p_cnt = 0;
	while (map_data[row] != NULL)
	{
		col = 0;
		while (map_data[row][col] != '\0')
		{
			if (ft_strchr("SNEW", map_data[row][col]))
				p_cnt++;
			else if (!ft_strchr("10 ", map_data[row][col]))
				error_exit("Invalid map char");
			col++;
		}
		if (map_info->map_w < col)
			map_info->map_w = col;
		row++;
	}
	map_info->map_h = row - 6;
	if (p_cnt != 1)
		error_exit("Player is not 1");
	if (map_info->map_h < 3 || map_info->map_w < 3)
		error_exit("Invalid map size");
}

void	map_init(t_map *map_info)
{
	int	idx;

	idx = 0;
	map_info->map = malloc(sizeof(char *) * (map_info->map_h + 1));
	if (map_info->map == NULL)
		error_exit("malloc failed");
	while (idx < map_info->map_h)
	{
		map_info->map[idx] = malloc(map_info->map_w + 1);
		if (map_info->map[idx] == NULL)
			error_exit("malloc failed");
		idx++;
	}
	map_info->map[idx] = NULL;
}

void	map_creat(t_map *map_info, char **map_data, \
				int str_row, int map_row)
{
	int	col;

	while (map_row < map_info->map_h)
	{
		col = 0;
		while (map_data[str_row][col] != '\0')
		{
			if (ft_strchr("SNEW", map_data[str_row][col]))
			{
				map_info->p_x = col;
				map_info->p_y = map_row;
			}
			map_info->map[map_row][col] = map_data[str_row][col];
			col++;
		}
		while (col < map_info->map_w)
		{
			map_info->map[map_row][col] = ' ';
			col++;
		}
		map_info->map[map_row][col] = '\0';
		str_row++;
		map_row++;
	}
}

void	map_info_creat(t_map *map_info, char **map_data)
{
	map_char_and_size_check(map_info, map_data, 6, 0);
	map_init(map_info);
	map_creat(map_info, map_data, 6, 0);
}
