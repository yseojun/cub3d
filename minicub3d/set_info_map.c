/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:34:03 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/04 16:44:46 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static char	**map_realloc(char **map, char *map_str);

char	**set_map_info(int fd)
{
	char	*temp;
	char	*map_str;
	char	**map;

	map = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			exit(EXIT_FAILURE);
		if (ft_strncmp(temp, "\n", 2))
			break ;
		free(temp);
	}
	while (1)
	{
		map_str = ft_strtrim(temp, "\n");
		free(temp);
		map = map_realloc(map, map_str);
		free(map_str);
		temp = get_next_line(fd);
		if (!temp)
			break ;
	}
	return (map);
}

static char	**map_realloc(char **map, char *map_str)
{
	int		height;
	char	**new;

	height = 0;
	if (map)
	{
		while (map[height])
			height++;
	}
	new = (char **)malloc(sizeof(char *) * (height + 2));
	new[height + 1] = NULL;
	new[height] = ft_strdup(map_str);
	while (height > 0)
	{
		new[height - 1] = ft_strdup(map[height - 1]);
		height--;
	}
	free_str_arr(map);
	return (new);
}
