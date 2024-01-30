/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:01:21 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/30 11:55:15 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "libft.h"

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
	void	*wall_north;
	void	*wall_south;
	void	*wall_east;
	void	*wall_west;
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

char	*convert_file_to_str(int fd);
void	convert_map_nl_check(char *temp_str);
int		file_name_check(char *full_name);
// file_convert

void	valid_make_texture(t_img *texture, t_mlx mlx, char **converted_str);
void	valid_make_map(t_map *map_info, char **converted_str);
// valid_make_handling

int		color_make(int red, int green, int blue);
// valid_make_utils

void	texture_img_creat(t_img *texture, void *mlx, char *img_str);
void	texture_rgb_creat(t_img *texture, char *rgb_str);
// valid_make_texture

void	map_info_creat(t_map *map_info, char **converted_str);
void	map_valid_check(t_map *map_info);
// valid_make_map

#endif
