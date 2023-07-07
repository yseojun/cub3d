/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 15:51:32 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	rotate(t_info *info, int sign, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player.dir[X];
	old_plane_x = info->player.plane[X];
	info->player.dir[X] = info->player.dir[X] * cos(angle * sign)
		- info->player.dir[Y] * sin(angle * sign);
	info->player.dir[Y] = old_dir_x * sin(angle * sign)
		+ info->player.dir[Y] * cos(angle * sign);
	info->player.plane[X] = info->player.plane[X] * cos(angle * sign)
		- info->player.plane[Y] * sin(angle * sign);
	info->player.plane[Y] = old_plane_x * sin(angle * sign)
		+ info->player.plane[Y] * cos(angle * sign);
}

int	press_key(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->ev.push_w = TRUE;
	if (keycode == KEY_A)
		info->ev.push_a = TRUE;
	if (keycode == KEY_S)
		info->ev.push_s = TRUE;
	if (keycode == KEY_D)
		info->ev.push_d = TRUE;
	if (keycode == KEY_LEFT_ARROW)
		info->ev.push_left = TRUE;
	if (keycode == KEY_RIGHT_ARROW)
		info->ev.push_right = TRUE;
	if (keycode == KEY_ESC)
		finish_game(info);
	return (SUCCESS);
}

int	release_key(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->ev.push_w = FALSE;
	if (keycode == KEY_A)
		info->ev.push_a = FALSE;
	if (keycode == KEY_S)
		info->ev.push_s = FALSE;
	if (keycode == KEY_D)
		info->ev.push_d = FALSE;
	if (keycode == KEY_LEFT_ARROW)
		info->ev.push_left = FALSE;
	if (keycode == KEY_RIGHT_ARROW)
		info->ev.push_right = FALSE;
	return (SUCCESS);
}

int	no_event(t_info *info)
{
	if ((info->ev.push_a && info->ev.push_w)
		|| (info->ev.push_d && info->ev.push_w)
		|| (info->ev.push_a && info->ev.push_s)
		|| (info->ev.push_d && info->ev.push_s))
		_move(info, 0.5);
	else if (info->ev.push_a || info->ev.push_w
		|| info->ev.push_d || info->ev.push_s)
		_move(info, 1);
	if (info->ev.push_left)
		rotate(info, -1, 0.1);
	else if (info->ev.push_right)
		rotate(info, 1, 0.1);
	display_3d(info);
	return (SUCCESS);
}

void	set_event(t_info *info)
{
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, 3, 0, &release_key, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &finish_game, info);
	mlx_loop_hook(info->mlx, &no_event, info);
}
