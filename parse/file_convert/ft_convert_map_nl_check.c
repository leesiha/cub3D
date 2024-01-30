/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map_nl_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:02:54 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/29 18:03:28 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_start_find(char *temp_str)
{
	int	idx;
	int	start;

	idx = 0;
	while (temp_str[idx] != '\0')
	{
		while (temp_str[idx] == '\n')
			idx++;
		start = idx;
		while (temp_str[idx] == ' ')
			idx++;
		if (ft_strncmp(temp_str + idx, "F ", 2) && \
			ft_strncmp(temp_str + idx, "C ", 2) && \
			ft_strncmp(temp_str + idx, "NO ", 3) && \
			ft_strncmp(temp_str + idx, "SO ", 3) && \
			ft_strncmp(temp_str + idx, "WE ", 3) && \
			ft_strncmp(temp_str + idx, "EA ", 3))
			return (start);
		while (temp_str[idx] != '\n')
			idx++;
		idx++;
	}
	return (ERROR);
}

void	convert_map_nl_check(char *temp_str)
{
	int	idx;

	idx = map_start_find(temp_str);
	if (idx == ERROR)
		error_exit("There is no map in file");
	else if (idx == 0)
		error_exit("There is only map in file");
	while (temp_str[idx + 1] != '\0')
	{
		if (temp_str[idx] == '\n' && temp_str[idx + 1] == '\n')
			error_exit("wrong char");
		idx++;
	}
}
