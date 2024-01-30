/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_img_creat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:08:35 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/30 11:53:17 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_name_find(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != ' ')
		idx++;
	while (str[idx] == ' ')
		idx++;
	return (idx);
}

void	texture_img_creat(t_img *texture, void *mlx, char *img_str)
{
	int	file_name;

	file_name = file_name_find(img_str);
	if (img_str[0] == 'S' && texture->wall_south == NULL)
		texture->wall_south = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
	else if (img_str[0] == 'N' && texture->wall_north == NULL)
		texture->wall_north = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
	else if (img_str[0] == 'E' && texture->wall_east == NULL)
		texture->wall_east = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
	else if (img_str[0] == 'W' && texture->wall_west == NULL)
		texture->wall_west = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
}
