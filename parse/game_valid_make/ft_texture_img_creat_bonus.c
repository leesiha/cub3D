/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_img_creat_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:08:35 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:38:50 by sihlee           ###   ########.fr       */
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
	if (img_str[0] == 'S' && texture->wall[2] == NULL)
		texture->wall[2] = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
	else if (img_str[0] == 'N' && texture->wall[3] == NULL)
		texture->wall[3] = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
	else if (img_str[0] == 'E' && texture->wall[0] == NULL)
		texture->wall[0] = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
	else if (img_str[0] == 'W' && texture->wall[1] == NULL)
		texture->wall[1] = mlx_xpm_file_to_image(mlx, img_str + file_name, \
													&texture->w, &texture->h);
}
