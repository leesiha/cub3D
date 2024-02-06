/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:00:17 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/06 22:04:20 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	le()
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("argument is not 1");
	atexit(le);
	parse(&game, argv[1]);
	visualize(&game);
}
