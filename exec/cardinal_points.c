/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:50:43 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 14:23:26 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color_north(t_game *g, t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = g->texture[1][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[0][TEXTURE_W * w->texture_y + w->texture_x];
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = g->texture[3][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[2][TEXTURE_W * w->texture_y + w->texture_x];
	}
}

void	set_color_south(t_game *g, t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = g->texture[0][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[1][TEXTURE_W * w->texture_y + w->texture_x];
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = g->texture[2][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[3][TEXTURE_W * w->texture_y + w->texture_x];
	}
}

void	set_color_west(t_game *g, t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = g->texture[3][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[2][TEXTURE_W * w->texture_y + w->texture_x];
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = g->texture[1][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[0][TEXTURE_W * w->texture_y + w->texture_x];
	}
}

void	set_color_east(t_game *g, t_dda *d, t_wall *w)
{
	if (d->side == 0)
	{
		if (d->ray_xv < 0)
			w->color = g->texture[2][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[3][TEXTURE_W * w->texture_y + w->texture_x];
	}
	else
	{
		if (d->ray_yv > 0)
			w->color = g->texture[0][TEXTURE_W * w->texture_y + w->texture_x];
		else
			w->color = g->texture[1][TEXTURE_W * w->texture_y + w->texture_x];
	}
}

void	set_wall_color(t_game *g, t_dda *d, t_wall *w)
{
	if (g->player.cardinal_points == 'N')
		set_color_north(g, d, w);
	else if (g->player.cardinal_points == 'S')
		set_color_south(g, d, w);
	else if (g->player.cardinal_points == 'W')
		set_color_west(g, d, w);
	else if (g->player.cardinal_points == 'E')
		set_color_east(g, d, w);
}
