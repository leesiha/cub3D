/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:51:00 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/12 12:52:13 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->map_info.p_x + 0.5;
	game->player.pos_y = game->map_info.p_y + 0.5;
	game->player.cardinal_points = \
		game->map_info.map[game->map_info.p_y][game->map_info.p_x];
	game->player.dir_xv = 0;
	game->player.dir_yv = 1;
	game->player.plane_xv = 0.66;
	game->player.plane_yv = 0;
	game->player.curser_x = -1;
}

void	get_img_data(t_game *game, int direction)
{
	int	width;
	int	x;
	int	height;
	int	y;

	width = game->img.w;
	height = game->img.h;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			game->texture[direction][width * y + x] = \
				game->drawing.addr[width * y + x];
			x++;
		}
		y++;
	}
}

void	init_draw(t_game *game)
{
	t_data	*ptr;
	int		direction;

	ptr = &(game->drawing);
	direction = 0;
	while (direction < 4)
	{
		ptr->img = game->img.wall[direction];
		ptr->addr = (unsigned int *)mlx_get_data_addr(ptr->img, \
			&ptr->bits_per_pixel, &ptr->size_line, &ptr->endian);
		get_img_data(game, direction);
		direction++;
	}
	ptr->img = mlx_new_image(game->mlx.mlx_p, SCREEN_W, SCREEN_H);
	ptr->addr = (unsigned int *)mlx_get_data_addr(ptr->img, \
			&ptr->bits_per_pixel, &ptr->size_line, &ptr->endian);
}

int	render_map(t_game *game)
{
	clean_window(game);
	raycast(game);
	my_mlx_pixel_put(game);
	mlx_put_image_to_window(game->mlx.mlx_p, game->mlx.win_p, \
								game->drawing.img, 0, 0);
	return (0);
}

void	visualize(t_game *game)
{
	init_player(game);
	init_draw(game);
	render_map(game);
	mlx_hook(game->mlx.win_p, KEY_PRESS, 1L << 0, key_hook, game);
	mlx_hook(game->mlx.win_p, DESTROY_NOTIFY, 1L << 5, fin, 0);
	mlx_hook(game->mlx.win_p, MOTION_NOTIFY, 1L << 6, cursor_hook, game);
	mlx_loop(game->mlx.mlx_p);
}
