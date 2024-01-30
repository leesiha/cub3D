/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:21:25 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/30 11:29:37 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_sides_check(t_map *map_info)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (col < map_info->map_w)
	{
		if (!ft_strchr("1 ", map_info->map[0][col]))
			error_exit("Map is not surrounded by 1");
		col++;
	}
	while (row < map_info->map_h - 1)
	{
		if (!ft_strchr("1 ", map_info->map[row][0]) || \
			!ft_strchr("1 ", map_info->map[row][map_info->map_w - 1]))
			error_exit("Map is not surrounded by 1");
		row++;
	}
	col = 0;
	while (col < map_info->map_w)
	{
		if (!ft_strchr("1 ", map_info->map[map_info->map_h - 1][col]))
			error_exit("Map is not surrounded by 1");
		col++;
	}
}

int	now_char_surround_check(char **map, int row, int col)
{
	if (!ft_strchr("1 ", map[row + 1][col]) || \
		!ft_strchr("1 ", map[row - 1][col]) || \
		!ft_strchr("1 ", map[row][col + 1]) || \
		!ft_strchr("1 ", map[row][col - 1]))
		return (END);
	return (NEXT);
}

void	map_inside_check(t_map *map_info)
{
	int	row;
	int	col;

	row = 1;
	while (row < map_info->map_h - 1)
	{
		col = 1;
		while (col < map_info->map_w - 1)
		{
			if (map_info->map[row][col] == ' ' && \
				now_char_surround_check(map_info->map, row, col))
				error_exit("Map is not surrounded by 1");
			col++;
		}
		row++;
	}
}

void	map_valid_check(t_map *map_info)
{
	map_sides_check(map_info);
	map_inside_check(map_info);
}
