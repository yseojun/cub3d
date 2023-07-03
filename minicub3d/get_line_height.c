/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:43:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 15:13:55 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

int	get_line_height(t_info *info, t_ray *ray)
{
	int is_hit;

	is_hit = FALSE;
	while (!is_hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->hit[X] += ray->step[X];
			ray->side = X;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->hit[Y] += ray->step[Y];
			ray->side = Y;
		}
		if (info->map[ray->hit[Y]][ray->hit[X]] == '1')
			is_hit = 1;
	}
	if (ray->side == X)
		ray->perpWallDist = (ray->hit[X] - info->player.pos[X] + (1 - ray->step[X]) / 2) / ray->ray_dir[X];
	else
		ray->perpWallDist = (ray->hit[Y] - info->player.pos[Y] + (1 - ray->step[Y]) / 2) / ray->ray_dir[Y];
	return ((int)(HEIGHT / ray->perpWallDist));
}
