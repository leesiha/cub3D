/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 17:01:57 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "raycast.h"
# include "parse.h"

# define SCREEN_W 1920
# define SCREEN_H 1080
# define H SCREEN_H

# define TEXTURE_W 400
# define TEXTURE_H 400

# define KEY_PRESS 2
# define EXIT_BUTTON 17

typedef struct s_game
{
	t_map		map_info;
	t_mlx		mlx;
	t_img		img;
	t_data		drawing;
	t_player	player;
	int			*texture[4];
	int			**buffer;
}	t_game;

void	parse(t_game *game, char *full_name);

void	clean_window(t_game *game);
int		render_map(t_game *game);
void	visualize(t_game *game);
void	raycast(t_game *game);
void	my_mlx_pixel_put(t_game *g);
void	set_wall_color(t_game *g, t_dda *d, t_wall *w);

int		key_hook(int keycode, t_game *game);

void	error_exit(char *msg);
int		fin(void);

#endif
