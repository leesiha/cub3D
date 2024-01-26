/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:34:33 by taehkim2          #+#    #+#             */
/*   Updated: 2024/01/22 16:37:47 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *msg)
{
	write(2, "ERROR : ", 8);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}
