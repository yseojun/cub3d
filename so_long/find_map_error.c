/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:11:53 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 22:45:02 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_component_error(char *map_str, int *total_col_cnt)
{
	int	epc_cnt[3];
	int	idx;

	epc_cnt[0] = 0;
	epc_cnt[1] = 0;
	epc_cnt[2] = 0;
	idx = 0;
	while (map_str[idx])
	{
		if (map_str[idx] != '0' && map_str[idx] != '1' && map_str[idx] != '\n' \
		&& map_str[idx] != 'C' && map_str[idx] != 'E' && map_str[idx] != 'P')
			return (1);
		if (map_str[idx] == 'E')
			epc_cnt[0]++;
		else if (map_str[idx] == 'P')
			epc_cnt[1]++;
		else if (map_str[idx] == 'C')
			epc_cnt[2]++;
		idx++;
	}
	if (epc_cnt[0] != 1 || epc_cnt[1] != 1 || epc_cnt[2] < 1)
		return (1);
	*total_col_cnt = epc_cnt[2];
	return (0);
}

int	find_newline_error(char *map_str)
{
	int	idx;
	int	newline_count;

	if (map_str[0] == '\n')
		return (1);
	if (map_str[ft_strlen(map_str) - 1] == '\n')
		return (1);
	idx = 0;
	newline_count = 0;
	while (map_str[idx])
	{
		if (map_str[idx] == '\n')
			newline_count++;
		else
			newline_count = 0;
		if (newline_count > 1)
			return (1);
		idx++;
	}
	return (0);
}

int	find_rectangle_error(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (game->map_width == 0)
			game->map_width = j;
		else
		{
			if (game->map_width != j)
				return (1);
		}
		i++;
	}
	game->map_height = i;
	return (0);
}

int	find_wall_error(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return (1);
			if (i == game->map_height - 1 && map[i][j] != '1')
				return (1);
			if (j == 0 && map[i][j] != '1')
				return (1);
			if (j == game->map_width - 1 && map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_map_error(t_game *game)
{
	if (find_rectangle_error(game))
	{
		write(2, "Error\nMap is not rectangular.\n", 30);
		return (1);
	}
	if (find_wall_error(game))
	{
		write(2, "Error\nMap is not surrounded by walls.\n", 38);
		return (1);
	}
	if (find_vaild_path_error(game))
	{
		write(2, "Error\nThere is not a valid path in the map.\n", 44);
		return (1);
	}
	return (0);
}
