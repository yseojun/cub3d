#include "info.h"

void bresenham(t_info *info, int fromX, int fromY, int toX, int toY)
{
	int dx;
	int dy;
	int x;
	int y;
	int color = 0x00FF0000;

	dx = abs(toX - fromX);
	dy = abs(toY - fromY);
	x = fromX;
	y = fromY;
	int f = 2 * dy - dx;
	int dF_1 = 2 * dy;
	int dF_2 = 2 * (dy - dx);
	if (dx && dy / dx <= 1)
	{
		for (; x <= toX; x++)
		{
			mlx_pixel_put(info->mlx, info->win, x, y, color);
			if (f < 0)
				f += dF_1;
			else
			{
				y++;
				f += dF_2;
			}
		}
	}
	else
	{
		for (; y <= toY; y++)
		{
			mlx_pixel_put(info->mlx, info->win, x, y, color);
			if (f < 0 || dx == 0)
				f += dF_1;
			else
			{
				x++;
				f += dF_2;
			}
		}
	}
}