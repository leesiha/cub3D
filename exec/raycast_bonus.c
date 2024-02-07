/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:56:53 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 15:37:44 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	determine_step(t_player *p, t_dda *d)
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

void	init_dda(t_player *p, t_dda *d)
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
	determine_step(p, d);
}

void	run_dda(char **map, t_dda *d)
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

void	get_wall_info(t_player *p, t_dda *d, t_wall *w)
{
	if (d->side == 0)
		w->perp_wall_dist = (d->int_pos_x - p->pos_x + (1 - d->step_x) / 2) \
								/ d->ray_xv;
	else
		w->perp_wall_dist = (d->int_pos_y - p->pos_y + (1 - d->step_y) / 2) \
								/ d->ray_yv;
	w->wall_height = (H / w->perp_wall_dist);
	w->draw_start = (H / 2) + (-w->wall_height / 2);
	w->draw_end = (H / 2) + (w->wall_height / 2);
	if (w->draw_start < 0)
		w->draw_start = 0;
	if (w->draw_end >= H)
		w->draw_end = H - 1;
	if (d->side == 0)
		w->wall_x = p->pos_y + w->perp_wall_dist * d->ray_yv;
	else
		w->wall_x = p->pos_x + w->perp_wall_dist * d->ray_xv;
	w->wall_x -= floor(w->wall_x);
	w->texture_x = (int)(w->wall_x * (double)TEXTURE_W);
	if (d->side == 0 && d->ray_xv > 0)
		w->texture_x = TEXTURE_W - w->texture_x - 1;
	if (d->side == 1 && d->ray_yv < 0)
		w->texture_x = TEXTURE_W - w->texture_x - 1;
	w->step = 1.0 * TEXTURE_H / w->wall_height;
	w->texture_pos = (w->draw_start - H / 2 + w->wall_height / 2) * w->step;
}

void	raycast(t_game *game)
{
	t_dda		dda;
	t_wall		wall;
	int			x;
	int			y;

	x = 0;
	while (x < SCREEN_W)
	{
		dda.plane_x = 2 * x / (double)SCREEN_W - 1;
		init_dda(&game->player, &dda);
		run_dda(game->map_info.map, &dda);
		get_wall_info(&game->player, &dda, &wall);
		y = wall.draw_start;
		while (y < wall.draw_end)
		{
			wall.texture_y = (int)wall.texture_pos;
			wall.texture_pos += wall.step;
			set_wall_color(game, &dda, &wall);
			game->buffer[y][x] = wall.color;
			y++;
		}
		x++;
	}
}
