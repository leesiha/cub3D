/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:01:21 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/26 15:13:54 by taehkim2         ###   ########.fr       */
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
}	t_img;

typedef struct s_map
{
	int		**map;
	int		w;
	int		h;
	int		p_row;
	int		p_col;
}	t_map;

#endif
