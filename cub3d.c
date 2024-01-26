/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:00:17 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 18:39:55 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define mapWidth 24
#define mapHeight 24

int	main(int argc, char **argv)
{
	t_game	game;

	// game에 map_info 넣기
	// game에 mlx 넣기
	// game에 texture 넣기
	if (argc != 2)
		error_exit("argument is not 1");
	parse(&game, argv[1]);
	visualize(&game);
}
