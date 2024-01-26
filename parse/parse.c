/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:33:26 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/25 18:57:33 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	last_space_remove(char *str)
// {
// 	int	end_idx;

// 	end_idx = ft_strlen(str) - 1;
// 	while (str[end_idx] == ' ' && end_idx >= 0)
// 		end_idx--;
// 	str[end_idx + 1] = '\0';
// }

// void	map_valid_check(char **converted_str)
// {

// }

// void	parse_valid_check(char **converted_str)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < 6)
// 	{
// 		col = 0;
// 		last_space_remove(converted_str[row]);
// 		while (converted_str[row][col] != ' ')
// 			col++;
// 		if (converted)
// 	}
// }

void	parse(t_game_info *game, char *full_name)
{
	char	**converted_str;

	if (file_name_check(full_name))
		error_exit("invalid file_name");
	converted_str = parse_file_convert(full_name);
	// parse_valid_check();
	game_image_creat(game, converted_str);
	game_map_creat(&game->map_data, converted_str);
}
