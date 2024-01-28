/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:50:43 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/28 20:02:55 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_color_north(t_ddl *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0) // west
			w->color = create_trgb(0, 255, 0, 0);
		else // east
			w->color = create_trgb(0, 0, 255, 0);
	}
	else // side == 1
	{
		if (d->ray_yv > 0) // north
			w->color = create_trgb(0, 0, 0, 255);
		else // south
			w->color = create_trgb(0, 255, 255, 255);
	}
}

void set_color_south(t_ddl *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0) // 
			w->color = create_trgb(0, 0, 255, 0);
		else // 
			w->color = create_trgb(0, 255, 0, 0);
	}
	else // side == 1
	{
		if (d->ray_yv > 0) // south
			w->color = create_trgb(0, 255, 255, 255);
		else // north
			w->color = create_trgb(0, 0, 0, 255);
	}
}

void set_color_west(t_ddl *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0) // 
			w->color = create_trgb(0, 0, 0, 255);
		else // 
			w->color = create_trgb(0, 255, 255, 255);
	}
	else // side == 1
	{
		if (d->ray_yv > 0) // west
			w->color = create_trgb(0, 255, 0, 0);
		else // east
			w->color = create_trgb(0, 0, 255, 0);
	}
}

void set_color_east(t_ddl *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0) // 
			w->color = create_trgb(0, 255, 255, 255);
		else // 
			w->color = create_trgb(0, 0, 0, 255);
	}
	else // side == 1
	{
		if (d->ray_yv > 0) // east
			w->color = create_trgb(0, 0, 255, 0);
		else // west
			w->color = create_trgb(0, 255, 0, 0);
	}
}

void set_wall_color(t_player *p, t_ddl *d, t_wall *w)
{
	if (p->cardinal_points == 'N')
		set_color_north(d, w);
	else if (p->cardinal_points == 'S')
		set_color_south(d, w);
	else if (p->cardinal_points == 'W')
		set_color_west(d, w);
	else if (p->cardinal_points == 'E')
		set_color_east(d, w);
	if (d->side == 1) // 그림자 효과?
		w->color = w->color / 2;
}