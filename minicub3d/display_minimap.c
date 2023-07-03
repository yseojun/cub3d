/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:18:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 17:18:14 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

// void	display_map(t_info *info)
// {
// 	int		i;
// 	int		j;
	
// 	i = -1;
// 	while (info->map[++i])
// 	{
// 		j = -1;
// 		while (info->map[i][++j])
// 		{
// 			if (info->map[i][j] != ' ')
// 				mlx_put_image_to_window(info->mlx, info->win, \
// 								info->so_texture, j * 64, i * 64);
// 			if (info->map[i][j] == '1')
// 				mlx_put_image_to_window(info->mlx, info->win, \
// 								info->no_texture, j * 64, i * 64);
// 			if (info->map[i][j] == 'P')
// 				mlx_put_image_to_window(info->mlx, info->win, \
// 								info->we_texture, j * 64, i * 64);
// 		}
// 	}
// }

// void	display_player(t_info *info)
// {
// 	int hit = 0;
// 	double	nowX;
// 	double	nowY;
// 	double	distX = 0;
// 	double	distY = 0;
// 	t_draw dr;

// 	nowX = info->player.posX;
// 	nowY = info->player.posY;
// 	while (hit == 0)
// 	{
// 		nowX += info->player.planeX;
// 		distX += info->player.planeX;
// 		nowY += info->player.planeY;
// 		distY += info->player.planeY;
// 		if (info->map[(int)nowY][(int)nowX] == '1')
// 			hit = 1;
// 	}
// 	dr = make_dr_info(info->player.posX * 64, info->player.posY * 64, nowX * 64, nowY * 64);
// 	bresenham(info, dr);
// }