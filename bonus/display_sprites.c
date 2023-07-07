/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:36:50 by rolee             #+#    #+#             */
/*   Updated: 2023/07/07 18:32:11 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	sort_sprites(t_info *info);

void	display_sprite(t_info *info)
{
	t_sprite_info	spr;
	int				i;

	get_sprite_distance(info);
	sort_sprite(info);
	i = 0;
	while (i < info->sprite_cnt)
	{
		calculate_sprite(info, spr, i);
		draw_each_sprite(info, spr, i);
		i++;
	}
}

void	calculate_sprite(t_info *info, t_sprite_info spr, int i)
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
}

void	draw_each_sprite(t_info *info, t_sprite_info spr, int i)
{
	int	drawstart[2];
	int	drawend[2];
	int	x;
	int	tex_x;

	drawstart[Y] = -spr.sprite_height / 2 + HEIGHT / 2;
	if (drawstart[Y] < 0)
		drawstart[Y] = 0;
	drawend[Y] = spr.sprite_height / 2 + HEIGHT / 2;
	if (drawend[Y] >= HEIGHT)
		drawend[Y] = HEIGHT - 1;
	spr.sprite_width = abs((int)(HEIGHT / spr.transform[Y]));
	drawstart[X] = -spr.sprite_width / 2 + spr.sprite_screen_x;
	if (drawstart[X] < 0)
		drawstart[X] = 0;
	drawend[X] = spr.sprite_width / 2 + spr.sprite_screen_x;
	if (drawend[X] >= WIDTH)
		drawend[X] = WIDTH - 1;
	x = drawstart[X];
	while (x < drawend[X])
	{
		tex_x = 
		x++;
	}
}

int	get_sprite_tex_x(t_info *info, t_sprite_info spr, int i, int x)
{
	int	tex_x;
	int	tex_width;
	int	screen_ratio;
	int	x_ratio;

	tex_width = info->sprites[i].frame[info->sprites[i].idx].width;
	x_ratio = tex_width / spr.sprite_width;
	screen_ratio = (-spr.sprite_width / 2 + spr.sprite_screen_x);
	tex_x = (int)(256 * (x - screen_ratio) * x_ratio);
	return (tex_x);
}

void	change_sprite(t_info *info, int time)
{
	
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
