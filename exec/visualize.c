/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:51:00 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/28 20:18:05 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->map_info.p_col;
	game->player.pos_y = game->map_info.p_row;
	game->player.cardinal_points = game->map_info.map[game->map_info.p_row][game->map_info.p_col];
	game->player.dir_xv = 0;
	game->player.dir_yv = 1;
	game->player.plane_xv = 0.66;
	game->player.plane_yv = 0;
}

void	init_draw(t_game *game)
{
	t_data	*ptr;

	ptr = &(game->drawing);
	ptr->img = mlx_new_image(game->mlx.p, SCREEN_WIDTH, SCREEN_HEIGHT);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->size_line, &ptr->endian);
}

int	render_map(t_game *game)
{
	clean_window(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx.p, game->mlx.win, game->drawing.img, 0, 0);
	return (0);
}

void	visualize(t_game *game)
{
	init_player(game);
	init_draw(game);
	render_map(game);
	mlx_hook(game->mlx.win, 2, 0, key_hook, game);
	mlx_loop(game->mlx.p);
}
