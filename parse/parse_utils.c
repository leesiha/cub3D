/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:37:03 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/25 18:13:31 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	th_free(char *str)
{
	free(str);
	str = NULL;
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

int	value_idx_find(char *str, int idx)
{
	while (str[idx] != ' ')
		idx++;
	while (str[idx] == ' ' || str[idx] == ',')
		idx++;
	return (idx);
}
