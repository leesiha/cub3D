/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_rgb_creat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:17:23 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/06 14:36:38 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rgb_char_check(char *rgb_str)
{
	int	idx;
	int	comma_cnt;

	idx = 1;
	comma_cnt = 0;
	while (rgb_str[idx] != '\0')
	{
		if (rgb_str[idx] != ' ' && rgb_str[idx] != ',' \
			&& (rgb_str[idx] < '0' || rgb_str[idx] > '9'))
			error_exit("Invalid rgb char");
		if (rgb_str[idx] == ',')
			comma_cnt++;
		idx++;
	}
	if (comma_cnt != 2)
		error_exit("Invalid rgb form");
}

void	rgb_num_check(char *num)
{
	int	idx;

	idx = 0;
	while (num[idx] >= '0' && num[idx] <= '9')
		idx++;
	if (idx > 3 || ft_atoi(num) > 255)
		error_exit("Invalid rgb number");
}

void	rgb_valid_check(char *rgb_str, int idx, int cnt)
{
	rgb_char_check(rgb_str);
	while (rgb_str[idx] != '\0')
	{
		cnt++;
		while (rgb_str[idx] == ' ')
			idx++;
		if (rgb_str[idx] == ',')
			error_exit("Invalid rgb form");
		rgb_num_check(rgb_str + idx);
		while (rgb_str[idx] >= '0' && rgb_str[idx] <= '9')
			idx++;
		while (rgb_str[idx] == ' ')
			idx++;
		if (rgb_str[idx] == '\0')
			break ;
		if (rgb_str[idx] != ',')
			error_exit("Invalid rgb form");
		idx++;
	}
	if (cnt != 3)
		error_exit("Invalid rgb form");
}

int	rgb_find(char *rgb_str, int idx)
{
	while (rgb_str[idx] != ' ' && rgb_str[idx] != ',')
		idx++;
	while (rgb_str[idx] == ' ' || rgb_str[idx] == ',')
		idx++;
	return (idx);
}

void	texture_rgb_creat(t_img *texture, char *rgb_str)
{
	int	rgb_num;
	int	red;
	int	green;
	int	blue;

	rgb_valid_check(rgb_str, 1, 0);
	rgb_num = rgb_find(rgb_str, 0);
	red = ft_atoi(rgb_str + rgb_num);
	rgb_num = rgb_find(rgb_str, rgb_num);
	green = ft_atoi(rgb_str + rgb_num);
	rgb_num = rgb_find(rgb_str, rgb_num);
	blue = ft_atoi(rgb_str + rgb_num);
	if (rgb_str[0] == 'F' && texture->floor_color == -1)
		texture->floor_color = color_make(red, green, blue);
	else if (rgb_str[0] == 'C' && texture->ceiling_color == -1)
		texture->ceiling_color = color_make(red, green, blue);
}
