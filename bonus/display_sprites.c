/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:36:50 by rolee             #+#    #+#             */
/*   Updated: 2023/07/10 17:41:54 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	sort_sprites(t_info *info);
static int	get_sprite_color(t_info *info, t_sprite_info spr, \
	int tex_x, int tex_y);

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
		draw_each_sprite(info, spr);
		i++;
	}
}

void	calculate_sprite(t_info *info, t_sprite_info spr, int i)
{
	spr.each = &info->sprites[i];
	spr.sprite[X] = spr.each->pos[X] - info->player.pos[X];
	spr.sprite[Y] = spr.each->pos[Y] - info->player.pos[Y];
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

void	draw_each_sprite(t_info *info, t_sprite_info spr)
{
	int	x;
	int	tex_x;

	x = spr.drawstart[X];
	while (x < spr.drawend[X])
	{
		tex_x = get_sprite_tex_x(info, spr, x);
		if (!(spr.transform[Y] > 0 && x > 0 && x < WIDTH
				&& spr.transform[Y] < info->z_buffer[x]))
			continue ;
		draw_sprite_y(info, spr, tex_x, x);
		x++;
	}
}

void	draw_sprite_y(t_info *info, t_sprite_info spr, int tex_x, int x)
{
	char	*tx;
	int		y;
	int		tex_y;
	int		color;

	tx = info->frame.addr + y * info->frame.line_length
		+ x * (info->frame.bits / 8);
	y = spr.drawstart[Y];
	while (y < spr.drawend[Y])
	{
		tex_y = ((y * 256 - HEIGHT * 128
					+ spr.sprite_height * 128 * spr.each->frame->height)
				/ spr.sprite_height) / 256;
		color = get_sprite_color(info, spr, tex_x, tex_y);
		if ((color & 0x00FFFFFF) != 0)
			*(unsigned int *)tx = color;
		y++;
	}
}

static int	get_sprite_color(t_info *info, t_sprite_info spr, \
	int tex_x, int tex_y)
{
	int	color;
	int	*tx;

	tx = (int *)spr.each->frame->addr;
	color = tx[tex_y * spr.each->frame->width + tex_x];
	return (color);
}

int	get_sprite_tex_x(t_info *info, t_sprite_info spr, int x)
{
	int	tex_x;
	int	tex_width;
	int	screen_ratio;
	int	x_ratio;

	tex_width = spr.each->frame[spr.each->idx].width;
	x_ratio = tex_width / spr.sprite_width;
	screen_ratio = (-spr.sprite_width / 2 + spr.sprite_screen_x);
	tex_x = (int)(256 * (x - screen_ratio) * x_ratio);
	return (tex_x);
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
