/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:38:31 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 17:46:25 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	int		idx;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	new_str[0] = 0;
	idx = 0;
	if (s1)
	{
		while (*s1)
		{
			new_str[idx++] = *s1;
			s1++;
		}
	}
	while (*s2)
	{
		new_str[idx++] = *s2;
		s2++;
	}
	new_str[idx] = 0;
	return (new_str);
}
