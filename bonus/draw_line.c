/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:27:06 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/05 15:28:04 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	bresenham(t_info *info, t_draw dr);

void	draw_line(t_info *info, t_ray *ray, int x, int line_height)
{
	int		start;
	int		end;
	int		color;
	t_draw	dr;

	color = 0xFF0000;
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	if (ray->side == X)
		color /= 2;
	dr = make_dr_info(x, start, x, end);
	bresenham(info, dr);
}

static void	draw_x(t_info *info, t_draw dr)
{
	int	x;
	int	y;
	int	dy;
	int	f;

	x = dr.from_x;
	y = dr.from_y;
	f = 2 * dr.dy - dr.dx;
	dy = 1;
	if (dr.from_y > dr.to_y)
		dy = -1;
	while (x <= dr.to_x)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, 0xFF0000);
		if (!dr.dy || f < 0)
			f += dr.df_1;
		else
		{
			y += dy;
			f += dr.df_2;
		}
		x++;
	}
}

static void	draw_y(t_info *info, t_draw dr)
{
	int	x;
	int	y;
	int	dx;
	int	f;

	x = dr.from_x;
	y = dr.from_y;
	f = 2 * dr.dy - dr.dx;
	dx = 1;
	if (dr.from_x > dr.to_x)
		dx = -1;
	while (y <= dr.to_y)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, 0xFF0000);
		if (!dr.dx || f < 0)
			f += dr.df_1;
		else
		{
			x += dx;
			f += dr.df_2;
		}
		y++;
	}
}

static void	bresenham(t_info *info, t_draw dr)
{
	if (dr.dx && dr.dy / dr.dx <= 1)
		draw_x(info, dr);
	else
		draw_y(info, dr);
}
