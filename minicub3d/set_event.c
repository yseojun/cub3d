/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/04 13:48:11 by seojyang         ###   ########.fr       */
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
	double	move_x;
	double	move_y;
	double	dpos_x;
	double	dpos_y;

	move_x = 0;
	move_y = 0;
	if (keycode == KEY_W || keycode == KEY_S)
		move_y = (keycode - 7) / 6;
	else
		move_x = keycode - 1;
	if (move_y)
	{
		dpos_x = info->player.dir[X] * move_y;
		dpos_y = info->player.dir[Y] * move_y;
	}
	if (move_x)
	{
		dpos_x = -info->player.dir[Y] * move_x;
		dpos_y = info->player.dir[X] * move_x;
	}
	info->player.pos[X] += dpos_x * SPEED;
	info->player.pos[Y] += dpos_y * SPEED;
	// 벽 뚫으면 어떻게..?
}

void	rotate(int keycode, t_info *info)
{
	double	sign;
	double	old_dir[2];

	sign = 1;
	if (keycode == KEY_LEFT_ARROW)
		sign = -1;
	old_dir = info->player.dir;
	info->player.dir[X] = -old_dir[X] * cos(ANGLE * sign)
		+ old_dir[Y] * sin(ANGLE * sign);
	info->player.dir[Y] = -old_dir[X] * sin(ANGLE * sign)
		- old_dir[Y] * cos(ANGLE * sign);
	info->player.plane[X] = -info->player.plane[X] * cos(ANGLE * sign)
		+ info->player.plane[Y] * sin(ANGLE * sign);
	info->player.plane[Y] = -info->player.plane[X] * sin(ANGLE * sign)
		- info->player.plane[Y] * cos(ANGLE * sign);
}

// void	open_door(t_info *info)
// {
	
// }

int	press_key(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move(keycode, info);
	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		rotate(keycode, info);
	// else if (keycode == KEY_SPACE)
	// 	open_door(info);
	display_3d(info);
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &press_close_button, info);
}
