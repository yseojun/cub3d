/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:07:27 by seojyang          #+#    #+#             */
/*   Updated: 2023/06/29 12:55:04 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

t_ray	set_ray(t_info *info, int x)
{
	t_ray	ray;
	double	cam_x;

	cam_x = 2 * x / (double)WIDTH - 1;
	ray.ray_dir[X] = info->player.dir[X] + info->player.plane[X] * cam_x;
	ray.ray_dir[Y] = info->player.dir[Y] + info->player.plane[Y] * cam_x;
	ray.map[X] = (int)info->player.pos[X];
	ray.map[Y] = (int)info->player.pos[Y];
	ray.delta_dist[X] = fabs(1 / ray.ray_dir[X]);
	ray.delta_dist[Y] = fabs(1 / ray.ray_dir[Y]);
	if (ray.ray_dir[X] < 0)
	{
		ray.step[X] = -1;
		ray.side_dist[X] = (info->player.pos[X] - ray.map[X]) * ray.delta_dist[X];
	}
	else
	{
		ray.step[X] = 1;
		ray.side_dist[X] = (ray.map[X] + 1.0 - info->player.pos[X]) * ray.delta_dist[X];
	}
	if (ray.ray_dir[Y] < 0)
	{
		ray.step[Y] = -1;
		ray.side_dist[Y] = (info->player.pos[Y] - ray.map[Y]) * ray.delta_dist[Y];
	}
	else
	{
		ray.step[Y] = 1;
		ray.side_dist[Y] = (ray.map[Y] + 1.0 - info->player.pos[Y]) * ray.delta_dist[Y];
	}
	return (ray);
}
