/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 15:46:44 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

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
	set_map_info(&info, fd);
	check_valid_map(info);
	set_player_info(&info);
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
