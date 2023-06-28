#include "info.h"

static void	draw_x(t_info *info, t_draw dr)
{
	int x;
	int y;
	int dy;
	int f;
 
	x = dr.fromX;
	y = dr.fromY;
	f = 2 * dr.dy - dr.dx;
	dy = 1;
	if (dr.fromY > dr.toY)
		dy = -1;
	while (x <= dr.toX)
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
	int x;
	int y;
	int dx;
	int f;
 
	x = dr.fromX;
	y = dr.fromY;
	f = 2 * dr.dy - dr.dx;
	dx = 1;
	if (dr.fromX > dr.toX)
		dx = -1;
	while (y <= dr.toY)
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

void bresenham(t_info *info, t_draw dr)
{
	if (dr.dx && dr.dy / dr.dx <= 1)
		draw_x(info, dr);
	else
		draw_y(info, dr);
}