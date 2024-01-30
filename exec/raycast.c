/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:56:53 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/30 22:17:27 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ddl(t_player *p, t_ddl *d)
{
	d->ray_xv = p->dir_xv + (p->plane_xv * d->plane_x);
	d->ray_yv = p->dir_yv + (p->plane_yv * d->plane_x);
	d->int_pos_x = (int)(p->pos_x);
	d->int_pos_y = (int)(p->pos_y);
	if (d->ray_xv == 0)
		d->delta_dist_x = INFINITY;
	else
		d->delta_dist_x = fabs(1 / d->ray_xv);
	if (d->ray_yv == 0)
		d->delta_dist_y = INFINITY;
	else
		d->delta_dist_y = fabs(1 / d->ray_yv);
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
	while (1)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->int_pos_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->int_pos_y += d->step_y;
			d->side = 1;
		}
		if (map[d->int_pos_y][d->int_pos_x] == '1')
			return ;
	}
}

void	get_wall_info(t_player *p, t_ddl *d, t_wall *w)
{
	double	perp_wall_dist;

	if (d->side == 0)
		perp_wall_dist = (d->int_pos_x - p->pos_x + (1 - d->step_x) / 2) / d->ray_xv;
	else
		perp_wall_dist = (d->int_pos_y - p->pos_y + (1 - d->step_y) / 2) / d->ray_yv;
	w->wall_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	w->draw_start = (SCREEN_HEIGHT / 2) + (-w->wall_height / 2);
	w->draw_end = (SCREEN_HEIGHT / 2) + (w->wall_height / 2);
	if (w->draw_start < 0)
		w->draw_start = 0;
	if (w->draw_end >= SCREEN_HEIGHT)
		w->draw_end = SCREEN_HEIGHT - 1;
	set_wall_color(p, d, w);
}

void	raycast(t_game *game)
{
	t_ddl		ddl;
	t_wall		wall;
	int			x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ddl.plane_x = 2 * x / (double)SCREEN_WIDTH - 1;
		init_ddl(&game->player, &ddl);
		determine_step(&game->player, &ddl);
		run_ddl(game->map_info.map, &ddl);
		get_wall_info(&game->player, &ddl, &wall);
		while (wall.draw_start < wall.draw_end)
		{
			my_mlx_pixel_put(&game->drawing, x, wall.draw_start, wall.color);
			wall.draw_start++;
		}
		x++;
	}
}
