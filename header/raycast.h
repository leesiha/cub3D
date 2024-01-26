/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 16:03:52 by taehkim2         ###   ########.fr       */
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
# define ESC 53

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

#endif
