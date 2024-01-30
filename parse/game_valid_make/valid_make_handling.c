/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_make_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:16:36 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/30 11:49:36 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_init(t_img *texture)
{
	texture->wall_south = NULL;
	texture->wall_north = NULL;
	texture->wall_east = NULL;
	texture->wall_west = NULL;
	texture->floor_color = -1;
	texture->ceiling_color = -1;
}

void	map_info_init(t_map *map_info)
{
	map_info->map_h = 0;
	map_info->map_w = 0;
	map_info->p_x = 0;
	map_info->p_y = 0;
	map_info->map = NULL;
}

void	valid_make_map(t_map *map_info, char **converted_str)
{
	map_info_init(map_info);
	map_info_creat(map_info, converted_str);
	map_valid_check(map_info);
}

void	valid_make_texture(t_img *texture, t_mlx mlx, char **converted_str)
{
	int	row;
	int	col;

	row = 0;
	texture_init(texture);
	while (row < 6)
	{
		col = 0;
		while (converted_str[row][col] == ' ')
			col++;
		if (!ft_strncmp(converted_str[row] + col, "SO ", 3) || \
			!ft_strncmp(converted_str[row] + col, "NO ", 3) || \
			!ft_strncmp(converted_str[row] + col, "WE ", 3) || \
			!ft_strncmp(converted_str[row] + col, "EA ", 3))
			texture_img_creat(texture, mlx.mlx_p, \
							converted_str[row] + col);
		else if (!ft_strncmp(converted_str[row] + col, "F ", 2) || \
				!ft_strncmp(converted_str[row] + col, "C ", 2))
			texture_rgb_creat(texture, converted_str[row] + col);
		row++;
	}
	if (texture->wall_south == NULL || texture->wall_north == NULL || \
		texture->wall_west == NULL || texture->wall_east == NULL || \
		texture->floor_color == -1 || texture->ceiling_color == -1)
		error_exit("Invalid texture form");
}
