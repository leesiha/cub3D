/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/28 20:16:06 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "raycast.h"
# include "parse.h"

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

typedef struct s_game
{
	t_map		map_info;
	t_mlx		mlx;
	t_img		texture;
	t_data		drawing;
	t_player	player;
}	t_game;

void	parse(t_game *game, char *full_name);

void	clean_window(t_game *game);
int		render_map(t_game *game);
void	visualize(t_game *game);
void	raycast(t_game *game);
int		key_hook(int keycode, t_game *game);

void	error_exit(char *msg);

#endif
