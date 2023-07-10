/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/10 18:31:06 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	init_ev(t_info *info);

t_info	set_info(char *path)
{
	t_info	info;
	int		fd;

	info.mlx = mlx_init();
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	init_ev(&info);
	set_graphic_info(&info, fd);
	info.texture[DOOR] = load_to_image(&info, DOOR_FILE_PATH);
	set_map_info(&info, fd);
	check_valid_map(info);
	set_player_info(&info);
	set_sprites(&info);
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
