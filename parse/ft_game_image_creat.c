/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_image_creat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:49:05 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/25 18:58:17 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	last_space_remove(char *str)
{
	int	end_idx;

	end_idx = ft_strlen(str) - 1;
	while (str[end_idx] == ' ' && end_idx >= 0)
		end_idx--;
	str[end_idx + 1] = '\0';
}

void	image_texture_creat(t_texture_info *texture, char *texture_str)
{
	int	value_idx;

	value_idx = value_idx_find(texture_str, 0);
	(void)texture;
	// if (texture_str[0] == 'S')
	// 	texture->south = mlx_xpm_file_to_image(mlx, \
	// 	texture_str + value_idx, &texture->width, &texture->height);
	// else if (texture_str[0] == 'N')
	// 	texture->north = mlx_xpm_file_to_image(mlx, \
	// 	texture_str + value_idx, &texture->width, &texture->height);
	// else if (texture_str[0] == 'W')
	// 	texture->west = mlx_xpm_file_to_image(mlx, \
	// 	texture_str + value_idx, &texture->width, &texture->height);
	// else if (texture_str[0] == 'E')
	// 	texture->east = mlx_xpm_file_to_image(mlx, \
	// 	texture_str + value_idx, &texture->width, &texture->height);
}

void	image_fc_creat(t_fc_info *fc, char *fc_str)
{
	int	value_idx;

	if (fc_str[0] == 'F')
	{
		value_idx = value_idx_find(fc_str, 0);
		fc->floor[RED] = ft_atoi(fc_str + value_idx);
		value_idx = value_idx_find(fc_str, value_idx);
		fc->floor[GREEN] = ft_atoi(fc_str + value_idx);
		value_idx = value_idx_find(fc_str, value_idx);
		fc->floor[BLUE] = ft_atoi(fc_str + value_idx);
	}
	else if (fc_str[0] == 'C')
	{
		value_idx = value_idx_find(fc_str, 0);
		fc->ceiling[RED] = ft_atoi(fc_str + value_idx);
		value_idx = value_idx_find(fc_str, value_idx);
		fc->ceiling[GREEN] = ft_atoi(fc_str + value_idx);
		value_idx = value_idx_find(fc_str, value_idx);
		fc->ceiling[BLUE] = ft_atoi(fc_str + value_idx);
	}
}

void	game_image_creat(t_game_info *game, char **converted_str)
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
			image_texture_creat(&game->texture, converted_str[row] + col);
		else if (converted_str[row][col] == 'F' || \
				converted_str[row][col] == 'C')
			image_fc_creat(&game->fc, converted_str[row] + col);
		row++;
	}
}
