/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 15:25:28 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

int	finish_game(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

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
		info->ev.push_w = 1;
	if (keycode == KEY_A)
		info->ev.push_a = 1;
	if (keycode == KEY_S)
		info->ev.push_s = 1;
	if (keycode == KEY_D)
		info->ev.push_d = 1;
	if (keycode == KEY_LEFT_ARROW)
		info->ev.push_left = 1;
	if (keycode == KEY_RIGHT_ARROW)
		info->ev.push_right = 1;
	if (keycode == KEY_SPACE)
		manage_door(info);
	if (keycode == KEY_ESC)
		finish_game(info);
	return (0);
}

int	release_key(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->ev.push_w = 0;
	if (keycode == KEY_A)
		info->ev.push_a = 0;
	if (keycode == KEY_S)
		info->ev.push_s = 0;
	if (keycode == KEY_D)
		info->ev.push_d = 0;
	if (keycode == KEY_LEFT_ARROW)
		info->ev.push_left = 0;
	if (keycode == KEY_RIGHT_ARROW)
		info->ev.push_right = 0;
	return (0);
}

void	_move(t_info *info, double val)
{
	if (info->ev.push_w)
		move_up(info, val);
	if (info->ev.push_s)
		move_down(info, val);
	if (info->ev.push_a)
		move_left(info, val);
	if (info->ev.push_d)
		move_right(info, val);
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
	display_minimap(info);
	return (0);
}

int	mouse_move(int x, int y, t_info *info)
{
	y = 0;
	info->ev.mouse_dx = x - info->ev.prev_mouse_x;
	if (info->ev.mouse_dx == 0)
		return (0);
	else if (info->ev.mouse_dx < 0)
		rotate(info, 1, info->ev.mouse_dx * 0.001);
	else
		rotate(info, 1, info->ev.mouse_dx * 0.001);
	mlx_mouse_move(info->win, WIDTH / 2, HEIGHT / 2);
	info->ev.prev_mouse_x = WIDTH / 2;
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, 3, 0, &release_key, info);
	mlx_hook(info->win, 6, 0, &mouse_move, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &finish_game, info);
	mlx_loop_hook(info->mlx, &no_event, info);
}
