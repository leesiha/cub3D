/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 16:08:46 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "raycast.h"
# include "parse.h"

# define screenWidth 640
# define screenHeight 480

typedef struct s_game
{
	t_map		map_info;
	t_mlx		mlx;
	t_img		texture;
	t_data		drawing;
	t_player	player;
}	t_game;

void	visualize(t_game *game);
void	raycast(t_game *game);
void	error_exit(char *msg);

#endif
