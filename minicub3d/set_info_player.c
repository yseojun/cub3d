/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:33 by seojyang          #+#    #+#             */
/*   Updated: 2023/06/28 16:31:43 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static t_player	make_player(int x, int y, char dir)
{
	t_player player;
	const int dx[4] = {0, 0, -1, 1};
	const int dy[4] = {-1, 1, 0, 0};
	const char	dd[4] = {'N', 'S', 'W', 'E'};
	int i;

	player.pos[X] = x + 0.5;
	player.pos[Y] = y + 0.5;
	i = 0;
	while (i < 4)
	{
		if (dir == dd[i])
		{
			player.dir[X] = dx[i];
			player.dir[Y] = dy[i];
			player.plane[X] = -dy[i] * POV;
			player.plane[Y] = dx[i] * POV;
			break ;
		}
		i++;
	}
	return (player);
}

void	set_player(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'W' || info->map[i][j] == 'E')
			{
				info->player = make_player(i, j, info->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}
