/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:00:17 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/25 17:56:28 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game_info	game;

	if (argc != 2)
		error_exit("argument is not 1");
	parse(&game, argv[1]);
	printf("F : %d %d %d\n", game.fc.floor[0], game.fc.floor[1], game.fc.floor[2]);
	printf("C : %d %d %d\n", game.fc.ceiling[0], game.fc.ceiling[1], game.fc.ceiling[2]);
	for (int i = 0; game.map_data.map[i] != NULL; i++)
		printf("%s\n", game.map_data.map[i]);
}
