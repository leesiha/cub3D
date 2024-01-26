/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:55:18 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/25 17:05:50 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*th_strjoin(char *dst, char *src, int dst_len, int src_len)
{
	char	*comb;
	int		comb_idx;
	int		util_idx;

	comb_idx = 0;
	util_idx = 0;
	comb = (char *)malloc(dst_len + src_len + 2);
	if (comb == NULL)
	{
		if (dst != NULL)
			th_free(dst);
		return (NULL);
	}
	while (util_idx < dst_len)
		comb[comb_idx++] = dst[util_idx++];
	util_idx = 0;
	while (util_idx < src_len)
		comb[comb_idx++] = src[util_idx++];
	comb[comb_idx] = '\0';
	if (dst != NULL)
		th_free(dst);
	return (comb);
}

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

char	*convert_file_to_str(int fd)
{
	char	*temp_str;
	char	buf[11];
	int		byte;

	byte = 10;
	temp_str = NULL;
	while (byte == 10)
	{
		byte = read(fd, buf, 10);
		if (byte < 0)
		{
			close(fd);
			error_exit("read failed");
		}
		temp_str = th_strjoin(temp_str, buf, ft_strlen(temp_str), byte);
		if (temp_str == NULL)
		{
			close(fd);
			error_exit("malloc failed");
		}
	}
	close(fd);
	return (temp_str);
}

char	**parse_file_convert(char *full_name)
{
	char	*temp_str;
	char	**converted_str;
	int		fd;

	fd = open(full_name, O_RDONLY);
	if (fd < 0)
		error_exit("open failed");
	temp_str = convert_file_to_str(fd);
	if (temp_str[0] == '\0')
		error_exit("empty file");
	convert_map_nl_check(temp_str);
	converted_str = ft_split(temp_str, '\n');
	free(temp_str);
	if (converted_str == NULL)
		error_exit("malloc failed");
	return (converted_str);
}
