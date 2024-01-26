/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 14:55:18 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "raycast.h"

typedef struct s_game_info
{
	t_texture_info	texture;
	t_fc_info		fc;
	t_map_info		map_data;
	t_player_info	player;
}	t_game_info;

void	visualize(t_map *map_info);
void	error_exit(char *msg);

#endif
