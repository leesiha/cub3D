/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:01:21 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:51:42 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include <fcntl.h>

# define END	1
# define NEXT	0
# define ERROR	-1

typedef struct s_mlx
{
	void	*mlx_p;
	void	*win_p;
}	t_mlx;

typedef struct s_xpm_to_img
{
	void	*wall[4];
	int		floor_color;
	int		ceiling_color;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		map_w;
	int		map_h;
	int		p_x;
	int		p_y;
}	t_map;

char	*convert_file_to_str(char *full_name);
char	**convert_str_to_map_data(char *str);
// file_convert

void	valid_make_texture(t_img *texture, t_mlx mlx, char **map_data);
void	valid_make_map(t_map *map_info, char **map_data);
// valid_make_handling

int		color_make(int red, int green, int blue);
void	map_data_free(char **map_data);
// valid_make_utils

void	texture_img_creat(t_img *texture, void *mlx, char *img_str);
void	texture_rgb_creat(t_img *texture, char *rgb_str);
// valid_make_texture

void	map_info_creat(t_map *map_info, char **map_data);
void	map_valid_check(t_map *map_info);
// valid_make_map

#endif
