/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:00:17 by sihlee            #+#    #+#             */
/*   Updated: 2024/02/07 17:03:25 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_buffer(t_game *game)
{
	int	i;

	game->buffer = malloc(sizeof(int *) * SCREEN_H);
	if (game->buffer == NULL)
		error_exit("malloc failed");
	i = 0;
	while (i < SCREEN_H)
	{
		game->buffer[i] = malloc(sizeof(int) * SCREEN_W);
		if (game->buffer[i] == NULL)
			error_exit("malloc failed");
		i++;
	}
}

void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i] = malloc(sizeof(int) * TEXTURE_H * TEXTURE_W);
		if (game->texture[i] == NULL)
			error_exit("malloc failed");
		i++;
	}
}

void	free_buffer(t_game *game)
{
	int	i;

	i = 0;
	while (i < SCREEN_H)
	{
		free(game->buffer[i]);
		i++;
	}
	free(game->buffer);
}

void	free_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(game->texture[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("argument is not 1");
	parse(&game, argv[1]);
	init_buffer(&game);
	init_texture(&game);
	visualize(&game);
	free_buffer(&game);
	free_texture(&game);
}
