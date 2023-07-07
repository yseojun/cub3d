/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:25:08 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 18:41:21 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	display_background(t_info *info);

void	display_3d(t_info *info)
{
	t_ray	ray;
	int		x;
	int		line_height;

	x = 0;
	display_background(info);
	while (x < WIDTH)
	{
		ray = set_ray(info, x);
		line_height = get_line_height(info, &ray);
		set_frame(info, &ray, x, line_height);
		info->z_buffer[x] = ray.perp_wall_dist;
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img, 0, 0);
}

void	display_frame(t_info *info)
{
	display_3d(info);
	// display_sprite(info);
	display_minimap(info);
}

static void	display_background(t_info *info)
{
	int	i;
	int	j;
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

double	get_distance(double from_x, double from_y, double to_x, double to_y)
{
	double	dist_x;
	double	dist_y;

	dist_x = to_x - from_x;
	dist_y = to_y - from_y;
	return (sqrt(pow(dist_x, 2) + pow(dist_y, 2)));
}
