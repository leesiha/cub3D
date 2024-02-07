/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:33:26 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parse_mlx_init(t_game *game)
{
	game->mlx.mlx_p = mlx_init();
	if (game->mlx.mlx_p == NULL)
		error_exit("mlx_init failed");
	game->mlx.win_p = \
	mlx_new_window(game->mlx.mlx_p, SCREEN_W, SCREEN_H, "cub3D");
	if (game->mlx.win_p == NULL)
		error_exit("mlx_new_window failed");
}

char	**parse_file_convert(char *full_name)
{
	char	*str;
	char	**map_data;

	str = convert_file_to_str(full_name);
	map_data = convert_str_to_map_data(str);
	return (map_data);
}

void	parse_game_valid_make(t_game *game, char **map_data)
{
	valid_make_texture(&game->img, game->mlx, map_data);
	valid_make_map(&game->map_info, map_data);
	map_data_free(map_data);
}

void	parse(t_game *game, char *full_name)
{
	char	**map_data;

	map_data = parse_file_convert(full_name);
	parse_mlx_init(game);
	parse_game_valid_make(game, map_data);
}
