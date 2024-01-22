/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/21 17:27:43 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_vector
{
	double	pos_x; //플레이어의 초기 위치벡터
	double	pos_y;
	double	dir_x; //플레이어의 초기 방향벡터
	double	dir_y;
	double	plane_x; //플레이어의 카메라평면
	double	plane_y;
	double	ray_dir_x; //광선의 방향벡터
	double	ray_dir_y;
}	t_vector;

typedef struct s_player
{
	/* data */
}	t_player;


#endif