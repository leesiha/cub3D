/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/12 12:32:37 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "raycast_bonus.h"
# include "parse_bonus.h"

# define SCREEN_W 640
# define SCREEN_H 480
# define H SCREEN_H

# define TEXTURE_W 400
# define TEXTURE_H 400

# define KEY_PRESS 2
# define MOTION_NOTIFY 6
# define DESTROY_NOTIFY 17

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
int		cursor_hook(int cursor_x, int cursor_y, t_game *game);

void	error_exit(char *msg);
int		fin(void);

#endif
