/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/25 16:47:09 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define screenWidth 640
# define screenHeight 480

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_mlx
{
	void	*p;
	void	*win;
}	t_mlx;

typedef struct s_xpm_to_img
{
	void	*p;
	void	*wall_north;
	void	*wall_south;
	void	*wall_east;
	void	*wall_west;
}	t_img;

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
	double	pos_x;
	double	pos_y;
	// 캐릭터 벡터
	double	dir_xv;
	double	dir_yv;
	// 카메라평면 벡터(카메라 평면 == 플레이어가 게임창으로 보는 전경 == 게임창)
	double	plane_xv;
	double	plane_yv;
}	t_player;

typedef struct s_game
{
	t_map		*map_info;
	t_mlx		*mlx;
	t_img		*texture;
	t_data		*drawing;
	t_player	*player;

	double		*time; //프레임이 나오는 데 걸린 시간(초)
}	t_game;

void	raycast(t_game *game);

#endif