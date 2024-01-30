/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_file_to_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:01:21 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/30 09:01:13 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
