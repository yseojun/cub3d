/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 17:20:05 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

t_info	set_info(char *path)
{
	t_info	info;
	int		fd;

	info.mlx = mlx_init();
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	set_graphic_info(&info, fd);
	info.map = set_map_info(fd);
	set_player_info(&info);
	return (info);
}
