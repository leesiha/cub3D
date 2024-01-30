/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:51:00 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/30 23:42:21 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->map_info.p_x + 0.5;
	game->player.pos_y = game->map_info.p_y + 0.5;
	game->player.cardinal_points = game->map_info.map[game->map_info.p_y][game->map_info.p_x];
	game->player.dir_xv = 0;
	game->player.dir_yv = 1;
	game->player.plane_xv = 0.66;
	game->player.plane_yv = 0;
}

void	init_draw(t_game *game)
{
	t_data	*ptr;

	ptr = &(game->drawing);
	ptr->img = mlx_new_image(game->mlx.mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->size_line, &ptr->endian);
}

int	render_map(t_game *game)
{
	clean_window(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx_p, game->mlx.win_p, game->drawing.img, 0, 0);
	return (0);
}

void	visualize(t_game *game)
{
	init_player(game);
	init_draw(game);
	render_map(game);
	mlx_hook(game->mlx.win_p, 2, 0, key_hook, game);
	mlx_loop(game->mlx.mlx_p);
}
