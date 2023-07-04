/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:27:49 by rolee             #+#    #+#             */
/*   Updated: 2023/07/04 17:28:28 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void	check_edge(t_info info, int y);
static void	check_around(char **map, int y, int x);

void	check_valid_map(t_info info)
{
	int	y;
	int	x;

	y = 0;
	while (info.map[y])
	{
		check_edge(info, y);
		x = 0;
		while (info.map[y][x])
		{
			if (info.map[y][x] != '1' && info.map[y][x] != ' ')
				check_around(info.map, y, x);
			x++;
		}
		y++;
	}
}

static void	check_edge(t_info info, int y)
{
	int	idx;

	if (y == 0 || y == info.map_size[HEI] - 1)
	{
		idx = 0;
		while(info.map[y][idx])
		{
			if (info.map[y][idx] != '1' && info.map[y][idx] != ' ')
				exit(EXIT_FAILURE);
			idx++;
		}
	}
	if (info.map[y][0] != '1' && info.map[y][0] != ' ')
		exit(EXIT_FAILURE);
	if (info.map[y][info.map_size[WID] - 1] != '1' && info.map[y][info.map_size[WID] - 1] != ' ')
		exit(EXIT_FAILURE);
}

static void	check_around(char **map, int y, int x)
{
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		exit(EXIT_FAILURE);
	if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		exit(EXIT_FAILURE);
	if (map[y + 1][x] == ' ' || map[y + 1][x] == '\0')
		exit(EXIT_FAILURE);
	if (map[y - 1][x] == ' ' || map[y - 1][x] == '\0')
		exit(EXIT_FAILURE);
}
