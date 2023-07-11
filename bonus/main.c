/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/07/11 14:38:32 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	set_mouse(t_info *info);

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2)
		return (occur_error("Invalid Argument."));
	info = set_info(argv[1]);
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "cub3d");
	set_mouse(&info);
	display_frame(&info);
	manage_event(&info);
	mlx_loop(info.mlx);
	return (0);
}

static void	set_mouse(t_info *info)
{
	int	tmp;

	mlx_mouse_move(info->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_get_pos(info->win, &info->ev.prev_mouse_x, &tmp);
	mlx_mouse_hide();
}
