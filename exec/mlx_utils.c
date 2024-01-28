/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:56:40 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/28 16:03:37 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	clean_window(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < screenHeight / 2)
	{
		x = 0;
		while (x < screenWidth)
		{
			my_mlx_pixel_put(&game->drawing, x, y, game->texture.ceiling_color);
			x++;
		}
		y++;
	}
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			my_mlx_pixel_put(&game->drawing, x, y, game->texture.floor_color);
			x++;
		}
		y++;
	}
}
