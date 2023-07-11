/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/11 14:14:50 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	init_ev(t_info *info);
static void	set_imgs(t_info *info);

t_info	set_info(char *path)
{
	t_info	info;
	int		fd;

	info.mlx = mlx_init();
	if (!info.mlx)
		exit(occur_error("mlx_init() failed."));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(occur_error("Invalid file path."));
	init_ev(&info);
	set_graphic_info(&info, fd);
	set_map_info(&info, fd);
	check_valid_map(info);
	set_player_info(&info);
	set_sprites(&info);
	set_imgs(&info);
	return (info);
}

static void	init_ev(t_info *info)
{
	info->ev.push_a = FALSE;
	info->ev.push_d = FALSE;
	info->ev.push_s = FALSE;
	info->ev.push_w = FALSE;
	info->ev.push_left = FALSE;
	info->ev.push_right = FALSE;
}

static void	set_imgs(t_info *info)
{
	info->frame.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->frame.addr = mlx_get_data_addr(info->frame.img, &info->frame.bits, \
		&info->frame.line_length, &info->frame.endian);
	info->minimap.img = mlx_new_image(info->mlx, 200, 200);
	info->minimap.addr = mlx_get_data_addr(info->minimap.img, \
		&info->minimap.bits, &info->minimap.line_length, &info->minimap.endian);
}
