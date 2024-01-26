/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:51:00 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 20:29:18 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->map_info.p_col;
	game->player.pos_y = game->map_info.p_row;
	game->player.dir_xv = 0;
	game->player.dir_yv = 1;
	game->player.plane_xv = 0.66;
	game->player.plane_yv = 0;
}

void	init_draw(t_game *game)
{
	t_data *draw;

	draw = &(game->drawing);
	draw->img = mlx_new_image(game->mlx.p, screenWidth, screenHeight);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel, &draw->size_line, &draw->endian);
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

int	render_map(t_game *game)
{
	clean_window(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx.p, game->mlx.win, game->drawing.img, 0, 0);
	// mlx_destroy_image(game->mlx->p, game->drawing->img);
	return (0);
}

void move(t_game *game, double speed)
{
	int estimated_x;
	int estimated_y;

	estimated_x = game->player.pos_x + game->player.dir_xv * speed;
	estimated_y = game->player.pos_y + game->player.dir_yv * speed;
	if (game->map_info.map[estimated_x][estimated_y] == '0')
	{
		game->player.pos_x += game->player.dir_xv * speed;
		game->player.pos_y += game->player.dir_yv * speed;
	}
}

int	key_hook(int keycode, t_game *game)
{
	t_player *player;
	char **worldMap;

	player = &(game->player);
	worldMap = game->map_info.map;

	double frame_time; // frameTime은 현재 프레임이 나오는 데 걸린 시간(초)입니다.
	double move_speed, rotate_speed;

	frame_time = 0.03; // 프레임 시간을 고정합니다. 이렇게 하면 이동 속도가 프레임 속도에 의해 결정됩니다.
	move_speed = frame_time * 6.0;	 // the constant value is in squares/second
	rotate_speed = frame_time * 2.0; // the constant value is in radians/second

	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx.p, game->mlx.win);
		exit(0);
	}
	
	if (keycode == W)
	{
		if (worldMap[(int)(player->pos_x + player->dir_xv * move_speed)][(int)player->pos_y] == '0')
			player->pos_x += player->dir_xv * move_speed;
		if (worldMap[(int)player->pos_x][(int)(player->pos_y + player->dir_yv * move_speed)] == '0')
			player->pos_y += player->dir_yv * move_speed;
		render_map(game);
	}
	else if (keycode == S)
	{
		if (worldMap[(int)(player->pos_x - player->dir_xv * move_speed)][(int)player->pos_y] == '0')
			player->pos_x -= player->dir_xv * move_speed;
		if (worldMap[(int)player->pos_x][(int)(player->pos_y - player->dir_yv * move_speed)] == '0')
			player->pos_y -= player->dir_yv * move_speed;
		render_map(game);
	}
	else if (keycode == A)
	{
		if (worldMap[(int)(player->pos_x - player->dir_yv * move_speed)][(int)player->pos_y] == '0')
			player->pos_x -= player->dir_yv * move_speed;
		if (worldMap[(int)player->pos_x][(int)(player->pos_y - player->dir_xv * move_speed)] == '0')
			player->pos_y -= player->dir_xv * move_speed;
		render_map(game);
	}
	else if (keycode == D)
	{
		if (worldMap[(int)(player->pos_x + player->dir_yv * move_speed)][(int)player->pos_y] == '0')
			player->pos_x += player->dir_yv * move_speed;
		if (worldMap[(int)player->pos_x][(int)(player->pos_y + player->dir_xv * move_speed)] == '0')
			player->pos_y += player->dir_xv * move_speed;
		render_map(game);
	}
	
	if (keycode == left)
	{
		// both camera direction and camera plane must be rotated
		double old_dir_xv = player->dir_xv;
		player->dir_xv = player->dir_xv * cos(rotate_speed) - player->dir_yv * sin(rotate_speed);
		player->dir_yv = old_dir_xv * sin(rotate_speed) + player->dir_yv * cos(rotate_speed);
		double old_plane_xv = player->plane_xv;
		player->plane_xv = player->plane_xv * cos(rotate_speed) - player->plane_yv * sin(rotate_speed);
		player->plane_yv = old_plane_xv * sin(rotate_speed) + player->plane_yv * cos(rotate_speed);
		render_map(game);
	}
	else if (keycode == right)
	{
		// both camera direction and camera plane must be rotated
		double old_dir_xv = player->dir_xv;
		player->dir_xv = player->dir_xv * cos(-rotate_speed) - player->dir_yv * sin(-rotate_speed);
		player->dir_yv = old_dir_xv * sin(-rotate_speed) + player->dir_yv * cos(-rotate_speed);
		double old_plane_xv = player->plane_xv;
		player->plane_xv = player->plane_xv * cos(-rotate_speed) - player->plane_yv * sin(-rotate_speed);
		player->plane_yv = old_plane_xv * sin(-rotate_speed) + player->plane_yv * cos(-rotate_speed);
		render_map(game);
	}
	return (0);
}

void	visualize(t_game *game)
{
	// 받아온 맵 출력
	// for (int i = 0; i < game->map_info.h; i++)
	// {
	// 	for (int j = 0; j < game->map_info.w; j++)
	// 		printf("%c", game->map_info.map[i][j]);
	// 	printf("\n");
	// }
	init_player(game);
	init_draw(game);
	render_map(game);
	mlx_hook(game->mlx.win, 2, 0, key_hook, game);
	mlx_loop(game->mlx.p);
}
