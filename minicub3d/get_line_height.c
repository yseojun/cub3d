/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:43:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 12:38:45 by rolee            ###   ########.fr       */
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
		ray->perpWallDist = (ray->map[X] - info->player.pos[X] + (1 - ray->step[X]) / 2) / ray->ray_dir[X];
	else
		ray->perpWallDist = (ray->map[Y] - info->player.pos[Y] + (1 - ray->step[Y]) / 2) / ray->ray_dir[Y];
	return ((int)(HEIGHT / ray->perpWallDist));
}
