/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:51:00 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 15:40:37 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game, t_player *player)
{
	player->pos_x = game->map_info->p_col;
	player->pos_y = game->map_info->p_row;
	// player->pos_x = 22;
	// player->pos_y = 12;

	// (캐릭터 벡터 > 카메라평면 벡터) 그래서 FOV 는 90°보다 작다(1:1일 때 90°)
	player->dir_xv = 1; // 데카르트 좌표계 기준 왼쪽 방향
	player->dir_yv = 0;
	player->plane_xv = 0;
	player->plane_yv = 0.66; // 데카르트 좌표계 기준 위쪽 방향
}

void	init_draw(t_game *game, t_data *draw)
{
	draw->img = mlx_new_image(game->mlx->p, screenWidth, screenHeight);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel, &draw->size_line, &draw->endian);
}

int	key_hook(int keycode, t_game *game)
{
	t_player *player;
	int **worldMap;

	player = game->player;
	worldMap = game->map_info->map;

	double frame_time; // frameTime은 현재 프레임이 나오는 데 걸린 시간(초)입니다.
	double move_speed, rotate_speed;

	frame_time = 0.03; // 프레임 시간을 고정합니다. 이렇게 하면 이동 속도가 프레임 속도에 의해 결정됩니다.
	move_speed = frame_time * 6.0;	 // the constant value is in squares/second
	rotate_speed = frame_time * 2.0; // the constant value is in radians/second

	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx->p, game->mlx->win);
		exit(0);
	}
	
	if (keycode == W)
	{

		if (worldMap[(int)(player->pos_x + player->dir_xv * move_speed)][(int)player->pos_y] == 0)
			player->pos_x += player->dir_xv * move_speed;
		if (worldMap[(int)player->pos_x][(int)(player->pos_y + player->dir_yv * move_speed)] == 0)
			player->pos_y += player->dir_yv * move_speed;
	}
	else if (keycode == S)
	{
		if (worldMap[(int)(player->pos_x - player->dir_xv * move_speed)][(int)player->pos_y] == 0)
			player->pos_x -= player->dir_xv * move_speed;
		if (worldMap[(int)player->pos_x][(int)(player->pos_y - player->dir_yv * move_speed)] == 0)
			player->pos_y -= player->dir_yv * move_speed;
	}
	
	if (keycode == D)
	{
		// both camera direction and camera plane must be rotated
		double old_dir_xv = player->dir_xv;
		player->dir_xv = player->dir_xv * cos(rotate_speed) - player->dir_yv * sin(rotate_speed);
		player->dir_yv = old_dir_xv * sin(rotate_speed) + player->dir_yv * cos(rotate_speed);
		double old_plane_xv = player->plane_xv;
		player->plane_xv = player->plane_xv * cos(rotate_speed) - player->plane_yv * sin(rotate_speed);
		player->plane_yv = old_plane_xv * sin(rotate_speed) + player->plane_yv * cos(rotate_speed);
	}
	else if (keycode == A)
	{
		// both camera direction and camera plane must be rotated
		double old_dir_xv = player->dir_xv;
		player->dir_xv = player->dir_xv * cos(-rotate_speed) - player->dir_yv * sin(-rotate_speed);
		player->dir_yv = old_dir_xv * sin(-rotate_speed) + player->dir_yv * cos(-rotate_speed);
		double old_plane_xv = player->plane_xv;
		player->plane_xv = player->plane_xv * cos(-rotate_speed) - player->plane_yv * sin(-rotate_speed);
		player->plane_yv = old_plane_xv * sin(-rotate_speed) + player->plane_yv * cos(-rotate_speed);
	}
	return (0);
}

int	render_map(t_game *game)
{
	t_data	draw;

	init_draw(game, &draw);
	game->drawing = &draw;
	mlx_put_image_to_window(game->mlx->p, game->mlx->win, draw.img, 0, 0);
	raycast(game);
	// mlx_put_image_to_window(game->mlx->p, game->mlx->win, draw.img, 0, 0);
	mlx_destroy_image(game->mlx->p, draw.img);
	return (0);
}

void	visualize(t_game *game)
{
	t_mlx		mlx;
	// t_img		texture;
	t_player	player;

	init_player(&game, &player);
	game->player = &player;

	mlx_hook(mlx.win, 2, 0, key_hook, game);
	mlx_loop_hook(mlx.p, render_map, game);
	mlx_loop(mlx.p);
}
