/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:34:33 by taehkim2          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:51 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	error_exit(char *msg)
{
	write(2, "ERROR : ", 8);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

int	fin(void)
{
	exit(0);
}
