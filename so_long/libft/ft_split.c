/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:33:45 by rolee             #+#    #+#             */
/*   Updated: 2023/01/11 12:53:23 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_word_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	get_space_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (i);
		i++;
	}
	return (i);
}

int	get_word_count(const char *str)
{
	int	idx;
	int	count;

	idx = get_space_len(str);
	count = 0;
	while (str[idx])
	{	
		idx += get_word_len(&str[idx]);
		idx += get_space_len(&str[idx]);
		count++;
	}
	return (count);
}

int	alloc_and_put(char **result, const char *str, int word_idx)
{
	int	idx;

	idx = 0;
	result[word_idx] = (char *)malloc(get_word_len(str) + 1);
	if (!result[word_idx])
	{
		while (idx < word_idx)
			free(result[idx++]);
		free(result);
		return (-1);
	}
	while (idx < get_word_len(str))
	{
		result[word_idx][idx] = str[idx];
		idx++;
	}
	result[word_idx][idx] = 0;
	return (0);
}

char	**ft_split(const char *str)
{
	int		word_count;
	char	**result;
	int		word_idx;
	int		str_idx;

	word_count = get_word_count(str);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	word_idx = 0;
	str_idx = get_space_len(str);
	while (word_idx < word_count)
	{
		if (alloc_and_put(result, &str[str_idx], word_idx) == -1)
			return (NULL);
		str_idx += get_word_len(&str[str_idx]);
		str_idx += get_space_len(&str[str_idx]);
		word_idx++;
	}
	result[word_idx] = 0;
	return (result);
}
