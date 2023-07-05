/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/07/05 15:28:09 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2)
		return (1);
	info = set_info(argv[1]);
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "so_long");
	info.frame.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.frame.addr = mlx_get_data_addr(info.frame.img, &info.frame.bits, \
		&info.frame.line_length, &info.frame.endian);
	info.minimap.img = mlx_new_image(info.mlx, 200, 200);
	info.minimap.addr = mlx_get_data_addr(info.minimap.img, &info.minimap.bits, \
		&info.minimap.line_length, &info.minimap.endian);
	display_3d(&info);
	display_minimap(&info);
	set_event(&info);
	mlx_loop(info.mlx);
	return (0);
}
