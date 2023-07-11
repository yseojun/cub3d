/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_each_sprite_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:17:01 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/11 14:58:15 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static int	get_sprite_tex_x(t_info *info, t_sprite_info spr, int i, int x);
static void	put_sprite_color_to_frame(t_info *info, int color, int x, int y);
static void	draw_sprite_y(t_info *info, t_sprite_info spr, int x, int tex_x, int i);
static int	get_sprite_color(t_info *info, int tex_x, int tex_y, int i);

void	display_each_sprite(t_info *info, t_sprite_info spr, int i)
{
	int	x;
	int	tex_x;

	x = spr.drawstart[X];
	while (x < spr.drawend[X])
	{
		tex_x = get_sprite_tex_x(info, spr, i, x);
		if (spr.transform[Y] > 0 && x > 0 && x < WIDTH
				&& spr.transform[Y] < info->z_buffer[x])
			draw_sprite_y(info, spr, x, tex_x, i);
		x++;
	}
}

static int	get_sprite_tex_x(t_info *info, t_sprite_info spr, int i, int x)
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

static void	draw_sprite_y(t_info *info, t_sprite_info spr, int x, int tex_x, int i)
{
	int	y;
	int	d;
	int	tex_y;
	int	color;

	y = spr.drawstart[Y];
	while (y < spr.drawend[Y])
	{
		d = y * 256 - HEIGHT * 128 + spr.sprite_height * 128;
		tex_y = ((d * info->sprites[i].frame->height) / spr.sprite_height)
			/ 256;
		color = get_sprite_color(info, tex_x, tex_y, i);
		if ((color & 0x00FFFFFF) != 0)
			put_sprite_color_to_frame(info, color, x, y);
		y++;
	}
}

static int	get_sprite_color(t_info *info, int tex_x, int tex_y, int i)
{
	int	texture_width;
	int	color;
	int	*tx;

	texture_width = info->sprites[i].frame[info->sprites[i].idx].width;
	tx = (int *)info->sprites[i].frame[info->sprites[i].idx].addr;
	color = tx[tex_y * texture_width + tex_x];
	return (color);
}

static void	put_sprite_color_to_frame(t_info *info, int color, int x, int y)
{
	int		*tx;

	tx = (int *)info->frame.addr;
	tx[y * WIDTH + x] = color;
}
