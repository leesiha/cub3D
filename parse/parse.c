/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:33:26 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/25 17:03:28 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(t_game_info *game, char *full_name)
{
	char	**converted_str;

	if (file_name_check(full_name))
		error_exit("invalid file_name");
	converted_str = parse_file_convert(full_name);
	game_image_creat(game, converted_str);
	game_map_creat(&game->map_data, converted_str);
}
