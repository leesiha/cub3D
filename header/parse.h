/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:01:21 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/26 16:17:05 by taehkim2         ###   ########.fr       */
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
	void	*p;
	void	*win;
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
	int		w;
	int		h;
	int		p_row;
	int		p_col;
}	t_map;

int		file_name_check(char *full_name);
void	th_free(char *str);
int		value_idx_find(char *str, int idx);
char	**parse_file_convert(char *full_name);
void	game_map_creat(t_map *map_data, char **converted_str);
void	game_image_creat(t_img *texture, t_mlx *mlx, char **converted_str);

#endif
