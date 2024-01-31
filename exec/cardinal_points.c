/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:50:43 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/31 20:58:20 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color_north(t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = create_trgb(0, 255, 0, 0);
		else
			w->color = create_trgb(0, 0, 255, 0);
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = create_trgb(0, 0, 0, 255);
		else
			w->color = create_trgb(0, 255, 255, 255);
	}
}

void	set_color_south(t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = create_trgb(0, 0, 255, 0);
		else
			w->color = create_trgb(0, 255, 0, 0);
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = create_trgb(0, 255, 255, 255);
		else
			w->color = create_trgb(0, 0, 0, 255);
	}
}

void	set_color_west(t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = create_trgb(0, 0, 0, 255);
		else
			w->color = create_trgb(0, 255, 255, 255);
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = create_trgb(0, 255, 0, 0);
		else
			w->color = create_trgb(0, 0, 255, 0);
	}
}

void	set_color_east(t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = create_trgb(0, 255, 255, 255);
		else
			w->color = create_trgb(0, 0, 0, 255);
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = create_trgb(0, 0, 255, 0);
		else
			w->color = create_trgb(0, 255, 0, 0);
	}
}

void	set_wall_color(t_player *p, t_dda *d, t_wall *w)
{
	if (p->cardinal_points == 'N')
		set_color_north(d, w);
	else if (p->cardinal_points == 'S')
		set_color_south(d, w);
	else if (p->cardinal_points == 'W')
		set_color_west(d, w);
	else if (p->cardinal_points == 'E')
		set_color_east(d, w);
	if (d->side == 1)
		w->color = w->color / 2;
}
