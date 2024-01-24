/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/24 20:07:03 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

// typedef struct s_player
// {
// 	// 캐릭터 위치(좌표)
// 	double	pos_x;
// 	double	pos_y;
// 	// 캐릭터 벡터
// 	double	dir_xv;
// 	double	dir_yv;
// 	// 카메라평면 벡터(카메라 평면 == 플레이어가 게임창으로 보는 전경 == 게임창)
// 	double	plane_xv;
// 	double	plane_yv;
// }	t_player;

// mlx 구조체 mlx 포인터와 생성할 win 포인터를 가지고 있다.
typedef struct	s_vars {
	void		*mlx;
	void		*win;
}	t_vars;

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

#endif