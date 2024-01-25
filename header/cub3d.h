/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:56:44 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/25 17:19:00 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "mlx.h"

# define END	1
# define NEXT	0
# define ERROR	-1
# define RED	0
# define GREEN	1
# define BLUE	2

typedef struct s_texture_info
{
	void	*south;
	void	*north;
	void	*west;
	void	*east;
	int		width;
	int		height;
}	t_texture_info;

typedef struct s_fc_info
{
	int	floor[3];
	int	ceiling[3];
}	t_fc_info;

typedef struct s_map_info
{
	char	**map;
	int		width;
	int		height;
}	t_map_info;

typedef struct s_player_info
{
	char	viewpoint;
	int		x;
	int		y;
}	t_player_info;

typedef struct s_game_info
{
	t_texture_info	texture;
	t_fc_info		fc;
	t_map_info		map_data;
	t_player_info	player;
}	t_game_info;

void	error_exit(char *msg);
char	*th_strjoin(char *dst, char *src, int dst_len, int src_len);
int		file_name_check(char *full_name);
void	th_free(char *str);
char	**parse_file_convert(char *full_name);
void	parse(t_game_info *game, char *full_name);
void	parse_game_info_creat(t_game_info *game, char **converted_str);
void	game_image_creat(t_game_info *game, char **converted_str);
void	game_map_creat(t_map_info *map_data, char **converted_str);


#endif
