/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_check_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:21:25 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	sides_space_check(char now_char, char check_char)
{
	if (now_char == ' ' && !ft_strchr("1 ", check_char))
		return (END);
	return (NEXT);
}

void	map_sides_check(char **map, int map_w, int map_h)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (col < map_w)
	{
		if (!ft_strchr("1 ", map[0][col]) || \
			!ft_strchr("1 ", map[map_h - 1][col]) || \
			sides_space_check(map[0][col], map[1][col]) || \
			sides_space_check(map[map_h - 1][col], map[map_h - 2][col]))
			error_exit("Map is not surrounded by 1");
		col++;
	}
	while (row < map_h - 1)
	{
		if (!ft_strchr("1 ", map[row][0]) || \
			!ft_strchr("1 ", map[row][map_w - 1]) || \
			sides_space_check(map[row][0], map[row][1]) || \
			sides_space_check(map[row][map_w - 1], map[row][map_w - 2]))
			error_exit("Map is not surrounded by 1");
		row++;
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
	map_sides_check(map_info->map, map_info->map_w, map_info->map_h);
	map_inside_check(map_info);
}
