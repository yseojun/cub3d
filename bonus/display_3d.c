/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:25:08 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/05 17:02:14 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	display_background(t_info *info);
// static void	sort_sprites(t_info *info);
// static double	get_diagonal_length(double from_x, double from_y, double to_x, double to_y);


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
		// sort_sprites(info);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img, 0, 0);
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

// static void	sort_sprites(t_info *info)
// {
// 	int			i;
// 	int			j;
// 	t_sprite	temp;

// 	i = 0;
// 	while (i < info->sprite_cnt - 1)
// 	{
// 		j = 0;
// 		while (j < info->sprite_cnt - 1 - i)
// 		{
// 			if (get_diagonal_length(info->player.pos[X], info->player.pos[Y], info->sprites[j].pos[X], info->sprites[j].pos[Y])
// 				< get_diagonal_length(info->player.pos[X], info->player.pos[Y], info->sprites[j + 1].pos[X], info->sprites[j + 1].pos[Y]))
// 			{
// 				temp = info->sprites[j];
// 				info->sprites[j] = info->sprites[j + 1];
// 				info->sprites[j + 1] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

double	get_diagonal_length(double from_x, double from_y, double to_x, double to_y)
{
	double	dist_x;
	double	dist_y;

	dist_x = to_x - from_x;
	dist_y = to_y - from_y;
	return (sqrt(pow(dist_x, dist_x) + pow(dist_y, dist_y)));
}
