/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:03:55 by sihlee            #+#    #+#             */
/*   Updated: 2023/03/23 16:32:35 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*trash;

	if (!*lst)
		return ;
	while (1)
	{
		if ((*lst)->next == NULL)
			break ;
		trash = (*lst);
		(*lst) = (*lst)->next;
		del(trash->content);
		free(trash);
	}
	del((*lst)->content);
	free((*lst));
	(*lst) = NULL;
}
