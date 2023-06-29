/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:43:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/06/29 12:33:34 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

int	get_line_height(t_info *info, t_ray *ray)
{
	int hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map[X] += ray->step[X];
			ray->side = X;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = Y;
		}
		if (info->map[ray->map[Y]][ray->map[X]] == '1')
			hit = 1;
	}
	if (ray->side == X)
	{
		printf("side : X\n");
		return ((int)(HEIGHT / (ray->map[X] - info->player.pos[X] + (1 - ray->step[X]) / 2) / ray->ray_dir[X]));
	}
	else
	{
		printf("side : Y\n");
		return ((int)(HEIGHT / (ray->map[Y] - info->player.pos[Y] + (1 - ray->step[Y]) / 2) / ray->ray_dir[Y]));
	}
}
