/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:56:53 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/28 20:01:48 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ddl(t_player *p, t_ddl *d)
{
	// 광선 방향 벡터 구하기
	d->ray_xv = p->dir_xv + (p->plane_xv * d->plane_x);
	d->ray_yv = p->dir_yv + (p->plane_yv * d->plane_x);
	d->int_pos_x = (int)(p->pos_x);
	d->int_pos_y = (int)(p->pos_y);
	//!!공식 유도 이해해야함
	// delta_dist_x = (ray_xv == 0) ? INFINITY : sqrt(1 + (ray_yv * ray_yv) / (ray_xv * ray_xv));
	// delta_dist_y = (ray_yv == 0) ? INFINITY : sqrt(1 + (ray_xv * ray_xv) / (ray_yv * ray_yv));
	d->delta_dist_x = (d->ray_xv == 0) ? INFINITY : fabs(1 / d->ray_xv);
	d->delta_dist_y = (d->ray_yv == 0) ? INFINITY : fabs(1 / d->ray_yv);
}

void	determine_step(t_player *p, t_ddl *d)
{
	if (d->ray_xv < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (p->pos_x - d->int_pos_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->int_pos_x + 1.0 - p->pos_x) * d->delta_dist_x;
	}

	if (d->ray_yv < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (p->pos_y - d->int_pos_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->int_pos_y + 1.0 - p->pos_y) * d->delta_dist_y;
	}
}

void	run_ddl(char **map, t_ddl *d)
{
	while (1) // 장애물(벽) 만날때까지 dist늘려가면서 확인하기
	{
		if (d->side_dist_x < d->side_dist_y) // 광선이 세로선과 가깝습니다.
		{
			d->side_dist_x += d->delta_dist_x;
			d->int_pos_x += d->step_x; // 이때 (사실상) x좌표는 1만큼 이동
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->int_pos_y += d->step_y;
			d->side = 1;
		}

		if (map[d->int_pos_x][d->int_pos_y] == '1') // Check if ray has hit a wall
			return;
	}
}

void	get_wall_info(t_player *p, t_ddl *d, t_wall *w)
{
	double	perp_wall_dist;
	//!!공식 유도 이해해야함
	// if (side == 0)
	// 	perp_wall_dist = side_dist_x - delta_dist_x;
	// else
	// 	perp_wall_dist = side_dist_y - delta_dist_y;
	if (d->side == 0)
		perp_wall_dist = (d->int_pos_x - p->pos_x + (1 - d->step_x) / 2) / d->ray_xv;
	else
		perp_wall_dist = (d->int_pos_y - p->pos_y + (1 - d->step_y) / 2) / d->ray_yv;
	// 내가 구한 광선 길이에 비례하여 세울 벽 높이 결정
	w->wall_height = (int)(screenHeight / perp_wall_dist);
	// 벽 그릴 픽셀 범위 지정
	w->draw_start = (screenHeight / 2) + (-w->wall_height / 2);
	w->draw_end = (screenHeight / 2) + (w->wall_height / 2);
	if (w->draw_start < 0)
		w->draw_start = 0;
	if (w->draw_end >= screenHeight)
		w->draw_end = screenHeight - 1;
	// 벽 색 지정
	set_wall_color(p, d, w);
}

void	raycast(t_game *game)
{
	t_ddl		ddl;
	t_wall		wall;

	for (int x = 0; x < screenWidth; x++) // 쏠 광선 수 == 전체 화면의 가로 픽셀 수
	{
		ddl.plane_x = 2 * x / (double)screenWidth - 1; // 화면의 픽셀 열 (x 좌표)을 정규화하여 [-1,1] 사이의 값으로 매핑.
		init_ddl(&game->player, &ddl);
		determine_step(&game->player, &ddl);
		run_ddl(game->map_info.map, &ddl);
		get_wall_info(&game->player, &ddl, &wall);
		// draw_vertical_line
		while (wall.draw_start < wall.draw_end)
		{
			my_mlx_pixel_put(&game->drawing, x, wall.draw_start, wall.color);
			wall.draw_start++;
		}
	}
}
