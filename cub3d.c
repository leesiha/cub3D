/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:00:17 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/26 15:40:26 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define mapWidth 24
#define mapHeight 24

void	init_mlx(t_mlx *x)
{
	x->p = mlx_init();
	// if (!x->p)
	// 	error_exit(0, "mlx_init failed");
	x->win = mlx_new_window(x->p, screenWidth, screenHeight, "cub3D");
	// if (!x->win)
	// 	error_exit(0, "mlx_new_window failed");
}

// void	init_texture(t_mlx *mlx, t_img *img) // 매개변수 수정 필요
// {
// 	int	w;
// 	int	h;

// 	img->p = mlx_xpm_file_to_image(mlx->p, "./textures/p.xpm", &w, &h);
// 	img->wall_north = mlx_xpm_file_to_image(mlx->p, "./textures/c.xpm", &w, &h);
// 	img->wall_south = mlx_xpm_file_to_image(mlx->p, "./textures/w.xpm", &w, &h);
// 	img->wall_east = mlx_xpm_file_to_image(mlx->p, "./textures/r.xpm", &w, &h);
// 	img->wall_west = mlx_xpm_file_to_image(mlx->p, "./textures/r.xpm", &w, &h);
// 	if (!img->p || !img->wall_north || !img->wall_south || !img->wall_east || !img->wall_west)
// 		error_exit(0, "mlx_xpm_file_to_image failed");
// }

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
