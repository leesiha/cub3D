/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_map_creat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:33:45 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/25 17:12:38 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_size_find(t_map_info *map_data, char **converted_str)
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
	map_data->height = row - 6;
	map_data->width = col;
}

void	map_init(t_map_info *map_data)
{
	int	idx;

	idx = 0;
	map_data->map = malloc(sizeof(char *) * (map_data->height + 1));
	if (map_data->map == NULL)
		error_exit("malloc failed");
	while (idx < map_data->height)
	{
		map_data->map[idx] = malloc(map_data->width + 1);
		if (map_data->map[idx] == NULL)
			error_exit("malloc failed");
		idx++;
	}
	map_data->map[idx] = NULL;
}

void	map_make(t_map_info *map_data, char **converted_str)
{
	int	str_row;
	int	map_row;
	int	col;

	str_row = 6;
	map_row = 0;
	while (map_row < map_data->height)
	{
		col = 0;
		while (col < map_data->width)
		{
			if (converted_str[str_row][col] != '\0')
				map_data->map[map_row][col] = converted_str[str_row][col];
			else
				map_data->map[map_row][col] = ' ';
			col++;
		}
		map_data->map[map_row][col] = '\0';
		str_row++;
		map_row++;
	}
}

void	game_map_creat(t_map_info *map_data, char **converted_str)
{
	map_size_find(map_data, converted_str);
	map_init(map_data);
	map_make(map_data, converted_str);
}
