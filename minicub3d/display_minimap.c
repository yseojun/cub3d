/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:18:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/04 17:31:39 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static char	get_map_inf(t_info *info, int mini_y, int mini_x)
{
	int	map_x;
	int	map_y;

	if (95 <= mini_x && mini_x <= 105 && 95 <= mini_y && mini_y <= 105)
		return ('m');
	map_y = floor(info->player.pos[Y] - ((double)5 / 100 * (100 - mini_y)));
	map_x = floor(info->player.pos[X] - ((double)5 / 100 * (100 - mini_x)));
	if (map_y < 0 || map_y >= 8 || map_x < 0 || map_x >= 10)
		return (0);
	else
		return (info->map[map_y][map_x]);
}

void	display_minimap(t_info *info)
{
	int		mini_x;
	int		mini_y;
	int		*mini;
	char	now;

	mini = (int *)info->minimap.addr;
	mini_y = 0;
	while (mini_y < 200)
	{
		mini_x = 0;
		while (mini_x < 200)
		{				
			now = get_map_inf(info, mini_y, mini_x);
			if (now == 0 || now == ' ')
				mini[mini_y * 200 + mini_x] = 0xCCCCCC;
			else if (now == '0')
				mini[mini_y * 200 + mini_x] = 0xCCFFCC;
			else if (now == '1')
				mini[mini_y * 200 + mini_x] = 0x003300;
			else if (now == 'm')
				mini[mini_y * 200 + mini_x] = 0xFF0000;
			mini_x++;
		}
		mini_y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->minimap.img, 25, 25);
}
