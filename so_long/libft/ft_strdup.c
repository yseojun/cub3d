/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:39:08 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 15:51:30 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		str_len;
	int		idx;

	str_len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!dest)
		return (NULL);
	idx = 0;
	while (idx < str_len)
	{
		dest[idx] = str[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}
