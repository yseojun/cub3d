/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:34:03 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/04 17:12:55 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static char		**set_rectangle_map(t_info *info, char **tmp_map);
static int		get_map_width(char **map);
static char		**read_map(int fd);
static char		**map_realloc(char **map, char *map_str);

void	set_map_info(t_info *info, int fd)
{
	char	**tmp_map;

	tmp_map = read_map(fd);
	info->map_size[HEI] = str_arr_len(tmp_map);
	info->map_size[WID] = get_map_width(tmp_map);
	info->map = set_rectangle_map(info, tmp_map);
}

static char	**set_rectangle_map(t_info *info, char **tmp_map)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * (info->map_size[HEI] + 1));
	i = 0;
	map[info->map_size[HEI]] = NULL;
	while(map[i])
	{
		map[i] = (char *)malloc(info->map_size[WID] + 1);
		j = 0;
		while(j < info->map_size[WID])
		{
			if (j < (int)ft_strlen(tmp_map[i]))
				map[i][j] = tmp_map[i][j];
			else
				map[i][j] = ' ';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

static int	get_map_width(char **map)
{
	int	max_width;
	int	idx;

	max_width = 0;
	idx = 0;
	while (map[idx])
	{
		if (max_width < (int)ft_strlen(map[idx]))
			max_width = ft_strlen(map[idx]);
		idx++;
	}
	return (max_width);
}

static char	**read_map(int fd)
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
		if (ft_strncmp(temp, "\n", 2) == 0)
			exit(EXIT_FAILURE);
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
