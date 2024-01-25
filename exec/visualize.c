/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:51:00 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/25 17:18:18 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include <sys/time.h> //gettimeofday 허용함수 아님!!

void	init_mlx(t_mlx *x)
{
	x->p = mlx_init();
	// if (!x->p)
	// 	error_exit(0, "mlx_init failed");
	x->win = mlx_new_window(x->p, screenWidth, screenHeight, "cub3D");
	// if (!x->win)
	// 	error_exit(0, "mlx_new_window failed");
}

// void	init_texture(t_mlx *mlx, t_img *img) // 매개변수 수정 필요
// {
// 	int	w;
// 	int	h;

// 	img->p = mlx_xpm_file_to_image(mlx->p, "./textures/p.xpm", &w, &h);
// 	img->wall_north = mlx_xpm_file_to_image(mlx->p, "./textures/c.xpm", &w, &h);
// 	img->wall_south = mlx_xpm_file_to_image(mlx->p, "./textures/w.xpm", &w, &h);
// 	img->wall_east = mlx_xpm_file_to_image(mlx->p, "./textures/r.xpm", &w, &h);
// 	img->wall_west = mlx_xpm_file_to_image(mlx->p, "./textures/r.xpm", &w, &h);
// 	if (!img->p || !img->wall_north || !img->wall_south || !img->wall_east || !img->wall_west)
// 		error_exit(0, "mlx_xpm_file_to_image failed");
// }

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

double	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	key_hook(int keycode, t_game *game)
{
	t_player *player;
	int **worldMap;

	player = game->player;
	worldMap = game->map_info->map;

	double frame_time; // frameTime은 현재 프레임이 나오는 데 걸린 시간(초)입니다.
	double move_speed, rotate_speed;
	double oldtime; // 현재 및 이전 프레임의 시간을 저장. 둘의 시간차는 특정키를 눌렀을 때 (프레임 계산하는데 얼마나 걸리건 일정한 속도로 움직이기 위해) 이동거리를 결정하고, FPS를 측정하는데 사용할 것입니다.

	// FPS 출력 !!이해해야함
	// 레이캐스팅 loop를 마친 후, 현재 프레임과 이전 프레임의 시간을 계산합니다.
	// 이 시간은 특정 키를 눌렀을 때 (프레임 계산하는데 얼마나 걸리건 일정한 속도로 움직이기 위해) 이동거리를 결정하고, FPS를 측정하는데 사용할 것입니다.
	oldtime = *(game->time);
	*(game->time) = get_time();
	frame_time = (*(game->time) - oldtime) / 1000.0; //frame_time은 초 단위입니다.
	printf("frame time: %f\n", frame_time);
	// print(1.0 / frame_time, 0, 0); //FPS 출력

	move_speed = frame_time * 3.0;	 // the constant value is in squares/second
	rotate_speed = frame_time * 1.0; // the constant value is in radians/second

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

void	visualize(t_map *map_info)
{
	t_mlx		mlx;
	// t_img		texture;
	t_player	player;
	t_game		game;
	double		time;

	game.map_info = map_info;
	init_mlx(&mlx);
	game.mlx = &mlx;
	// init_texture(&game, &texture);
	// game.texture = &texture;
	init_player(&game, &player);
	game.player = &player;
	time = 0;
	game.time = &time;

	mlx_hook(mlx.win, 2, 0, key_hook, &game);
	mlx_loop_hook(mlx.p, render_map, &game);
	mlx_loop(mlx.p);
}
