/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_make_handling_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:16:36 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	texture_init(t_img *texture)
{
	int	direction;

	direction = 0;
	while (direction < 4)
	{
		texture->wall[direction] = NULL;
		direction++;
	}
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

void	valid_make_map(t_map *map_info, char **map_data)
{
	map_info_init(map_info);
	map_info_creat(map_info, map_data);
	map_valid_check(map_info);
}

void	valid_make_texture(t_img *texture, t_mlx mlx, char **map_data)
{
	int	row;
	int	col;

	row = 0;
	texture_init(texture);
	(void)mlx;
	while (row < 6)
	{
		col = 0;
		while (map_data[row][col] == ' ')
			col++;
		if (!ft_strncmp(map_data[row] + col, "SO ", 3) || \
			!ft_strncmp(map_data[row] + col, "NO ", 3) || \
			!ft_strncmp(map_data[row] + col, "WE ", 3) || \
			!ft_strncmp(map_data[row] + col, "EA ", 3))
			texture_img_creat(texture, mlx.mlx_p, map_data[row] + col);
		if (!ft_strncmp(map_data[row] + col, "F ", 2) || \
			!ft_strncmp(map_data[row] + col, "C ", 2))
			texture_rgb_creat(texture, map_data[row] + col);
		row++;
	}
	if (texture->wall[0] == NULL || texture->wall[1] == NULL || \
		texture->wall[2] == NULL || texture->wall[3] == NULL || \
		texture->floor_color == -1 || texture->ceiling_color == -1)
		error_exit("Invalid texture form");
}
