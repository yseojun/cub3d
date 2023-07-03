/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:25:08 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 18:54:52 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void display_background(t_info *info);

void	display_3d(t_info *info)
{
	t_ray	ray;
	int		x;
	int		line_height;

	x = 0;
	info->frame.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->frame.addr = mlx_get_data_addr(info->frame.img, &info->frame.bits, \
		&info->frame.line_length, &info->frame.endian);
	display_background(info);
	while (x < WIDTH)
	{
		ray = set_ray(info, x);
		line_height = get_line_height(info, &ray);
		set_frame(info, &ray, x, line_height);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img, 0, 0);
}

int encode_rgb(int color[3])
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

static void display_background(t_info *info)
{
	int i;
	int j;
	int	*tx;

	tx = (int *)info->frame.addr;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				tx[i * WIDTH + j] = encode_rgb(info->c_color);
			else
				tx[i * WIDTH + j] = encode_rgb(info->f_color);
			j++;
		}
		i++;
	}
}
