/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:00:38 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate(t_player *player, double theta)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->dir_xv * cos(theta) - player->dir_yv * sin(theta);
	tmp_y = player->dir_xv * sin(theta) + player->dir_yv * cos(theta);
	player->dir_xv = tmp_x;
	player->dir_yv = tmp_y;
	tmp_x = player->plane_xv * cos(theta) - player->plane_yv * sin(theta);
	tmp_y = player->plane_xv * sin(theta) + player->plane_yv * cos(theta);
	player->plane_xv = tmp_x;
	player->plane_yv = tmp_y;
}

void	move_updown(t_player *player, char **map, double delta)
{
	double	estimated_x;
	double	estimated_y;

	estimated_x = player->pos_x + player->dir_xv * delta;
	estimated_y = player->pos_y + player->dir_yv * delta;
	if (map[(int)player->pos_y][(int)(estimated_x + 0.1)] != '1'
		&& map[(int)player->pos_y][(int)(estimated_x - 0.1)] != '1')
		player->pos_x = estimated_x;
	if (map[(int)(estimated_y + 0.1)][(int)player->pos_x] != '1'
		&& map[(int)(estimated_y - 0.1)][(int)player->pos_x] != '1')
		player->pos_y = estimated_y;
}

void	move_leftright(t_player *player, char **map, double delta)
{
	double	estimated_x;
	double	estimated_y;

	estimated_x = player->pos_x - player->dir_yv * delta;
	estimated_y = player->pos_y + player->dir_xv * delta;
	if (map[(int)player->pos_y][(int)(estimated_x + 0.1)] != '1'
		&& map[(int)player->pos_y][(int)(estimated_x - 0.1)] != '1')
		player->pos_x = estimated_x;
	if (map[(int)(estimated_y + 0.1)][(int)player->pos_x] != '1'
		&& map[(int)(estimated_y - 0.1)][(int)player->pos_x] != '1')
		player->pos_y = estimated_y;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		fin();
	if (keycode == W)
		move_updown(&game->player, game->map_info.map, MOVESPEED);
	else if (keycode == S)
		move_updown(&game->player, game->map_info.map, -MOVESPEED);
	else if (keycode == D)
		move_leftright(&game->player, game->map_info.map, -MOVESPEED);
	else if (keycode == A)
		move_leftright(&game->player, game->map_info.map, MOVESPEED);
	if (keycode == LEFT)
		rotate(&game->player, ROTSPEED);
	else if (keycode == RIGHT)
		rotate(&game->player, -ROTSPEED);
	render_map(game);
	return (0);
}
