/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_file_to_str_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:01:21 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	th_free(char *str)
{
	free(str);
	str = NULL;
}

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

char	*str_creat(int fd)
{
	char	*str;
	char	buf[11];
	int		byte;

	byte = 10;
	str = NULL;
	while (byte == 10)
	{
		byte = read(fd, buf, 10);
		if (byte < 0)
		{
			close(fd);
			error_exit("read failed");
		}
		str = th_strjoin(str, buf, ft_strlen(str), byte);
		if (str == NULL)
		{
			close(fd);
			error_exit("malloc failed");
		}
	}
	close(fd);
	return (str);
}

int	file_name_check(char *full_name)
{
	char	*file_name;
	char	*extension_name;

	if (ft_strlen(full_name) < 5)
		return (END);
	file_name = ft_strrchr(full_name, '/');
	if (file_name == NULL)
		file_name = full_name;
	else
		file_name++;
	extension_name = ft_strrchr(file_name, '.');
	if (extension_name == NULL)
		extension_name = file_name;
	if (file_name[1] == '.' || ft_strncmp(extension_name, ".cub", 4))
		return (END);
	return (NEXT);
}

char	*convert_file_to_str(char *full_name)
{
	char	*str;
	int		fd;

	if (file_name_check(full_name))
		error_exit("invalid file_name");
	fd = open(full_name, O_RDONLY);
	if (fd < 0)
		error_exit("open failed");
	str = str_creat(fd);
	if (str[0] == '\0')
		error_exit("empty file");
	return (str);
}
