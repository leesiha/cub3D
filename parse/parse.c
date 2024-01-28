/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:33:26 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/28 20:16:01 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(t_game *game, char *full_name)
{
	char	**converted_str;

	if (file_name_check(full_name))
		error_exit("invalid file_name");
	converted_str = parse_file_convert(full_name);
	game->mlx.p = mlx_init();
	if (game->mlx.p == NULL)
		error_exit("mlx_init failed");
	game->mlx.win = \
	mlx_new_window(game->mlx.p, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (game->mlx.win == NULL)
		error_exit("mlx_new_window failed");
	game_image_creat(&game->texture, &game->mlx, converted_str);
	game_map_creat(&game->map_info, converted_str);
}
