/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <taehkim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:47:19 by sihlee            #+#    #+#             */
/*   Updated: 2024/01/23 15:47:52 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (*s_copy)
		s_copy++;
	if ((char)c == 0)
		return ((char *)s_copy);
	else if ((char)c)
	{
		s_copy--;
		while (s <= s_copy)
		{
			if (*s_copy == (char)c)
				return ((char *)s_copy);
			else
				s_copy--;
		}
		return ((char *)0);
	}
	return ((char *)s_copy);
}
