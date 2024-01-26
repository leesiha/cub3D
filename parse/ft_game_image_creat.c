/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_image_creat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:49:05 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/26 18:23:45 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_make(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	last_space_remove(char *str)
{
	int	end_idx;

	end_idx = ft_strlen(str) - 1;
	while (str[end_idx] == ' ' && end_idx >= 0)
		end_idx--;
	str[end_idx + 1] = '\0';
}

void	image_texture_creat(t_img *texture, t_mlx *mlx, char *texture_str)
{
	int	value_idx;

	value_idx = value_idx_find(texture_str, 0);
	(void)texture;
	(void)mlx;
	// if (texture_str[0] == 'S')
	// 	texture->wall_south = mlx_xpm_file_to_image(mlx->p, \
	// 	texture_str + value_idx, &texture->w, &texture->h);
	// else if (texture_str[0] == 'N')
	// 	texture->wall_north = mlx_xpm_file_to_image(mlx->p, \
	// 	texture_str + value_idx, &texture->w, &texture->h);
	// else if (texture_str[0] == 'W')
	// 	texture->wall_west = mlx_xpm_file_to_image(mlx->p, \
	// 	texture_str + value_idx, &texture->w, &texture->h);
	// else if (texture_str[0] == 'E')
	// 	texture->wall_east = mlx_xpm_file_to_image(mlx->p, \
	// 	texture_str + value_idx, &texture->w, &texture->h);
}

void	image_fc_creat(t_img *texture, char *fc_str)
{
	int	value_idx;
	int	red;
	int	green;
	int	blue;

	value_idx = value_idx_find(fc_str, 0);
	red = ft_atoi(fc_str + value_idx);
	value_idx = value_idx_find(fc_str, value_idx);
	green = ft_atoi(fc_str + value_idx);
	value_idx = value_idx_find(fc_str, value_idx);
	blue = ft_atoi(fc_str + value_idx);
	if (fc_str[0] == 'F')
		texture->floor_color = color_make(red, green, blue);
	else if (fc_str[0] == 'C')
		texture->ceiling_color = color_make(red, green, blue);

}

void	game_image_creat(t_img *texture, t_mlx *mlx, char **converted_str)
{
	int	row;
	int	col;

	row = 0;
	while (row < 6)
	{
		col = 0;
		last_space_remove(converted_str[row]);
		while (converted_str[row][col] == ' ')
			col++;
		if (converted_str[row][col] == 'S' || \
			converted_str[row][col] == 'N' || \
			converted_str[row][col] == 'W' || \
			converted_str[row][col] == 'E')
			image_texture_creat(texture, mlx, converted_str[row] + col);
		else if (converted_str[row][col] == 'F' || \
				converted_str[row][col] == 'C')
			image_fc_creat(texture, converted_str[row] + col);
		row++;
	}
}
