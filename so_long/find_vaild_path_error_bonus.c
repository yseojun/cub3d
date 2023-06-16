/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vaild_path_error_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:05:44 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 23:01:54 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_p_location(char **map, int *y, int *x)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P' || map[*y][*x] == 'L' \
			|| map[*y][*x] == 'U' || map[*y][*x] == 'R')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

char	**duplicate_map(t_game *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		map_copy[i] = (char *)malloc(game->map_width + 1);
		if (!map_copy[i])
		{
			while (++j < i)
				free(map_copy[j]);
			free(map_copy);
			return (NULL);
		}
		while (game->map[i][++j])
			map_copy[i][j] = game->map[i][j];
		map_copy[i][j] = 0;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	check_exit_path(char **map, int y, int x, int *exit)
{
	if (map[y][x] == 'E')
		*exit += 1;
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		check_exit_path(map, y - 1, x, exit);
	if (map[y][x - 1] != '1')
		check_exit_path(map, y, x - 1, exit);
	if (map[y + 1][x] != '1')
		check_exit_path(map, y + 1, x, exit);
	if (map[y][x + 1] != '1')
		check_exit_path(map, y, x + 1, exit);
	return ;
}

void	check_collectible_path(char **map, int y, int x, int *collectible)
{
	if (map[y][x] == 'C')
		*collectible += 1;
	map[y][x] = '1';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
		check_collectible_path(map, y - 1, x, collectible);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
		check_collectible_path(map, y, x - 1, collectible);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
		check_collectible_path(map, y + 1, x, collectible);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
		check_collectible_path(map, y, x + 1, collectible);
	return ;
}

int	find_vaild_path_error(t_game *game)
{
	char	**map;
	int		y;
	int		x;
	int		exit_cnt;
	int		total_col_cnt;

	get_p_location(game->map, &y, &x);
	map = duplicate_map(game);
	if (!map)
		return (1);
	exit_cnt = 0;
	check_exit_path(map, y, x, &exit_cnt);
	free_map(map);
	if (exit_cnt != 1)
		return (1);
	map = duplicate_map(game);
	if (!map)
		return (1);
	total_col_cnt = 0;
	check_collectible_path(map, y, x, &total_col_cnt);
	free_map(map);
	if (total_col_cnt != game->total_col_cnt)
		return (1);
	return (0);
}
