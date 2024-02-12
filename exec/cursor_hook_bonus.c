/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:13:11 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/12 12:51:07 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	cursor_hook(int cursor_x, int cursor_y, t_game *game)
{
	int	prev_x;

	prev_x = game->player.curser_x;
	if ((cursor_x > 0 && cursor_x < SCREEN_W)
		&& (cursor_y > 0 && cursor_y < SCREEN_H))
	{
		if (prev_x == -1)
		{
			game->player.curser_x = cursor_x;
			return (0);
		}
		if (cursor_x < prev_x)
			rotate(&game->player, ROTSPEED);
		else
			rotate(&game->player, -ROTSPEED);
		game->player.curser_x = cursor_x;
	}
	render_map(game);
	return (0);
}
