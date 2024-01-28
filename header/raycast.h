/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/28 19:58:54 by sihlee           ###   ########.fr       */
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
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_player
{
	// 캐릭터 위치(좌표)
	char	cardinal_points;
	double	pos_x;
	double	pos_y;
	// 캐릭터 벡터
	double	dir_xv;
	double	dir_yv;
	// 카메라평면 벡터(카메라 평면 == 플레이어가 게임창으로 보는 전경 == 게임창)
	double	plane_xv;
	double	plane_yv;
}	t_player;

// DDA에서 사용할 변수. 광선 하나마다 이 값들이 모두 다를 것이다.
typedef struct s_ddl
{
	// pos_x, pos_y의 정수버전. 맵 인덱스 접근을 위해 사용
	int	int_pos_x;
	int	int_pos_y;
	// 광선을 카메라평면으로 쐈을 때 만나는 x 좌표. (실제 '평면'이 아니라 선을 만나는 것이기 때문에 x값으로만 정의해도 된다)
	double	plane_x;
	// 광선 벡터
	double	ray_xv;
	double	ray_yv;
	// 지금부터 플레이어가 빛을 광선 벡터 방향으로 쏠거다.
	// 빛은 그 길로 나아가면서 격자(맵을 격자로 나눠서 생각)의 세로선(x=1과 평행)과도 만나고, 가로선(y=1과 평행)과도 만난다.
	// 빛이 만나게 될 두 가지 선을 x, y로 분담해서 각각 확인하도록 한다.
	int	side;				// 광선이 현재 만난게 세로선(0)인지 가로선(1)인지 저장.
	double	side_dist_x;
	double	side_dist_y;	// '맨 처음 side'를 만나기 위해 '광선'이 나아가야 하는 거리. **이후 누적합으로 아래의 delta 변수를 계속해서 더할것이다.
	double	delta_dist_x;
	double	delta_dist_y;	// '다음 side'를 만나기 위해 '광선'이 나아가야 하는 거리. (x == 세로선 사이의 거리) (y == 가로선 사이의 거리)
	int	hit;				// 광선이 wall을 hit했습니까? yes(1) no(0)
	int	step_x;
	int	step_y;				// 광선이 현재 격자에서 다음 격자로 한 칸 이동. (DDA 실행 전에 한번만 ray_xv, ray_yv 검사해서 앞으로 빛이 이동할 방향을 정함)
}	t_ddl;

typedef struct wall
{
	int 	wall_height;	// perp_wall_dist에 비례하여 결정
	int 	draw_start;
	int 	draw_end;
	int 	color;
}	t_wall;

int 	create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	rotate(t_player *player, double theta);
void	move_updown(t_player *player, char **map, double delta);
void	move_leftright(t_player *player, char **map, double delta);
void	set_wall_color(t_player *p, t_ddl *d, t_wall *w);

#endif
