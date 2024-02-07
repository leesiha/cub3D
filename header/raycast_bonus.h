/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 15:40:37 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

# define MOVESPEED 0.1
# define ROTSPEED 0.05

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_data;

typedef struct s_player
{
	char	cardinal_points;
	double	pos_x;
	double	pos_y;
	double	dir_xv;
	double	dir_yv;
	double	plane_xv;
	double	plane_yv;
}	t_player;

typedef struct s_dda
{
	int		int_pos_x;
	int		int_pos_y;
	double	plane_x;
	double	ray_xv;
	double	ray_yv;
	int		side;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		hit;
	int		step_x;
	int		step_y;
}	t_dda;

typedef struct wall
{
	double	perp_wall_dist;
	double	wall_height;
	double	wall_x;
	int		texture_x;
	double	step;
	double	texture_pos;
	int		texture_y;
	int		draw_start;
	int		draw_end;
	int		color;
}	t_wall;

void	rotate(t_player *player, double theta);
void	move_updown(t_player *player, char **map, double delta);
void	move_leftright(t_player *player, char **map, double delta);

#endif
