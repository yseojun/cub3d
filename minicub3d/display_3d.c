/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:25:08 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 16:33:49 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	display_3d(t_info *info)
{
	t_ray	ray;
	int		x;
	int		line_height;

	x = 0;
	info->frame.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->frame.addr = mlx_get_data_addr(info->frame.img, &info->frame.bits, \
		&info->frame.line_length, &info->frame.endian);
	while (x < WIDTH)
	{
		ray = set_ray(info, x);
		line_height = get_line_height(info, &ray);
		set_frame(info, &ray, x, line_height);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img, 0, 0);
}
