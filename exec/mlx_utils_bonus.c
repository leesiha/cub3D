/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:56:40 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	my_mlx_pixel_put(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			game->drawing.addr[y * SCREEN_W + x] = game->buffer[y][x];
			x++;
		}
		y++;
	}
}

void	clean_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_H / 2)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			game->buffer[y][x] = game->img.ceiling_color;
			x++;
		}
		y++;
	}
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			game->buffer[y][x] = game->img.floor_color;
			x++;
		}
		y++;
	}
}
