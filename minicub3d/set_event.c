/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/04 15:22:52 by seojyang         ###   ########.fr       */
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
	if (info->map[(int)info->player.pos[Y]]\
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)] == '0')
		info->player.pos[X] += dpos_x * SPEED;
	if (info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)]\
		[(int)info->player.pos[X]] == '0')
		info->player.pos[Y] += dpos_y * SPEED;
}

// void	rotate(int keycode, t_info *info)
// {
// 	double	sign;
// 	double	old_dir[2];

// 	sign = 1;
// 	if (keycode == KEY_LEFT_ARROW)
// 		sign = -1;
// 	old_dir[X] = info->player.dir[X];
// 	old_dir[Y] = info->player.dir[Y];
// 	info->player.dir[X] = -old_dir[X] * cos(ANGLE * sign)
// 		+ old_dir[Y] * sin(ANGLE * sign);
// 	info->player.dir[Y] = -old_dir[X] * sin(ANGLE * sign)
// 		- old_dir[Y] * cos(ANGLE * sign);
// 	info->player.plane[X] = -info->player.plane[X] * cos(ANGLE * sign)
// 		+ info->player.plane[Y] * sin(ANGLE * sign);
// 	info->player.plane[Y] = -info->player.plane[X] * sin(ANGLE * sign)
// 		- info->player.plane[Y] * cos(ANGLE * sign);
// }

void	rotate(int keycode, t_info *info)
{
	double	sign;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player.dir[X];
	old_plane_x = info->player.plane[X];
	sign = 1;
	if (keycode == KEY_LEFT_ARROW)
		sign = -1;
	info->player.dir[X] = info->player.dir[X] * cos(ANGLE * sign)
		- info->player.dir[Y] * sin(ANGLE * sign);
	info->player.dir[Y] = old_dir_x * sin(ANGLE * sign)
		+ info->player.dir[Y] * cos(ANGLE * sign);
	info->player.plane[X] = info->player.plane[X] * cos(ANGLE * sign)
		- info->player.plane[Y] * sin(ANGLE * sign);
	info->player.plane[Y] = old_plane_x * sin(ANGLE * sign)
		+ info->player.plane[Y] * cos(ANGLE * sign);
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
