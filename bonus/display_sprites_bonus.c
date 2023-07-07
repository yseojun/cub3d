/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:36:50 by rolee             #+#    #+#             */
/*   Updated: 2023/07/07 19:18:53 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	sort_sprites(t_info *info);
static void	calculate_sprite(t_info *info, t_sprite_info spr, int i);

void	display_sprites(t_info *info)
{
	t_sprite_info	spr;
	int				idx;

	get_sprite_distance(info);
	sort_sprite(info);
	idx = 0;
	while (idx < info->sprite_cnt)
	{
		calculate_sprite(info, spr, idx);
		display_each_sprite(info, spr, idx);
		idx++;
	}
}

static void	calculate_sprite(t_info *info, t_sprite_info spr, int i)
{
	spr.sprite[X] = info->sprites[i].pos[X] - info->player.pos[X];
	spr.sprite[Y] = info->sprites[i].pos[Y] - info->player.pos[Y];
	spr.inv_det = 1.0 / (info->player.plane[X] * info->player.dir[Y]
			- info->player.plane[Y] * info->player.dir[X]);
	spr.transform[X] = spr.inv_det * (info->player.dir[Y] * spr.sprite[X]
			- info->player.dir[X] * spr.sprite[Y]);
	spr.transform[Y] = spr.inv_det * (info->player.plane[X] * spr.sprite[Y]
			- info->player.plane[Y] * spr.sprite[X]);
	spr.sprite_screen_x = (int)((WIDTH / 2)
			* (1 + spr.transform[X] / spr.transform[Y]));
	spr.sprite_height = abs((int)(HEIGHT / spr.transform[Y]));
	spr.drawstart[Y] = -spr.sprite_height / 2 + HEIGHT / 2;
	if (spr.drawstart[Y] < 0)
		spr.drawstart[Y] = 0;
	spr.drawend[Y] = spr.sprite_height / 2 + HEIGHT / 2;
	if (spr.drawend[Y] >= HEIGHT)
		spr.drawend[Y] = HEIGHT - 1;
	spr.sprite_width = abs((int)(HEIGHT / spr.transform[Y]));
	spr.drawstart[X] = -spr.sprite_width / 2 + spr.sprite_screen_x;
	if (spr.drawstart[X] < 0)
		spr.drawstart[X] = 0;
	spr.drawend[X] = spr.sprite_width / 2 + spr.sprite_screen_x;
	if (spr.drawend[X] >= WIDTH)
		spr.drawend[X] = WIDTH - 1;
}

static void	sort_sprites(t_info *info)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < info->sprite_cnt - 1)
	{
		j = 0;
		while (j < info->sprite_cnt - 1 - i)
		{
			if (info->sprites[i].distance < info->sprites[i].distance)
			{
				temp = info->sprites[j];
				info->sprites[j] = info->sprites[j + 1];
				info->sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
