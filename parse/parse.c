/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:33:26 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/30 19:06:22 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_mlx_init(t_game *game)
{
	game->mlx.mlx_p = mlx_init();
	if (game->mlx.mlx_p == NULL)
		error_exit("mlx_init failed");
	game->mlx.win_p = \
	mlx_new_window(game->mlx.mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (game->mlx.win_p == NULL)
		error_exit("mlx_new_window failed");
}

char	**parse_file_convert(char *full_name)
{
	char	*temp_str;
	char	**converted_str;
	int		fd;

	if (file_name_check(full_name))
		error_exit("invalid file_name");
	fd = open(full_name, O_RDONLY);
	if (fd < 0)
		error_exit("open failed");
	temp_str = convert_file_to_str(fd);
	if (temp_str[0] == '\0')
		error_exit("empty file");
	convert_map_nl_check(temp_str);
	converted_str = ft_split(temp_str, '\n');
	free(temp_str);
	if (converted_str == NULL)
		error_exit("malloc failed");
	return (converted_str);
}

void	parse_game_valid_make(t_game *game, char **converted_str)
{
	valid_make_texture(&game->texture, game->mlx, converted_str);
	valid_make_map(&game->map_info, converted_str);
}

void	parse(t_game *game, char *full_name)
{
	char	**converted_str;
	int		idx;

	idx = 0;
	converted_str = parse_file_convert(full_name);
	parse_mlx_init(game);
	parse_game_valid_make(game, converted_str);
	while (converted_str[idx] != NULL)
	{
		free(converted_str[idx]);
		converted_str[idx] = NULL;
	}
	free(converted_str);
	converted_str = NULL;
}
