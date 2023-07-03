/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/07/03 19:39:05 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

int	press_close_button(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

void	move(int keycode, t_info *info)
{
	
}

void	rotate(int keycode, t_info *info)
{
	
}

void	open_door(t_info *info)
{
	
}

int	press_key(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		rotate(keycode, info);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		move(keycode, info);
	else if (keycode == KEY_SPACE)
		open_door(info);
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->win, 2, 2, &press_key, info);
	mlx_hook(info->win, 2, 2, &press_key, info);
	mlx_hook(info->win, 2, 2, &press_key, info);
	mlx_hook(info->win, 2, 2, &press_key, info);
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, 2, 2, &press_key, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &press_close_button, info);
}

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
	display_3d(&info);
	set_event(&info);
	mlx_loop(info.mlx);
	return (0);
}
