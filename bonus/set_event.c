/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/05 17:18:42 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

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
	if (info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)] == '0')
		info->player.pos[X] += dpos_x * SPEED;
	if (info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
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

void	rotate(t_info *info, int sign)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player.dir[X];
	old_plane_x = info->player.plane[X];
	info->player.dir[X] = info->player.dir[X] * cos(ANGLE * sign)
		- info->player.dir[Y] * sin(ANGLE * sign);
	info->player.dir[Y] = old_dir_x * sin(ANGLE * sign)
		+ info->player.dir[Y] * cos(ANGLE * sign);
	info->player.plane[X] = info->player.plane[X] * cos(ANGLE * sign)
		- info->player.plane[Y] * sin(ANGLE * sign);
	info->player.plane[Y] = old_plane_x * sin(ANGLE * sign)
		+ info->player.plane[Y] * cos(ANGLE * sign);
}

void	open_door(t_info *info)
{
	const int	dxy[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
	int			nx;
	int			ny;
	int			i;

	i = 0;
	while (i < 4)
	{
		ny = floor(info->player.pos[Y]) + dxy[Y][i];
		nx = floor(info->player.pos[X]) + dxy[X][i];
		if (ny < 0 || ny >= info->map_size[HEI]
			|| nx < 0 || nx >= info->map_size[WID])
			continue ;
		if (info->map[ny][nx] == '2')
		{
			if (get_diagonal_length(info->player.pos[X], \
				info->player.pos[Y], nx, ny) < 0.2)
				info->map[ny][nx] == 'O';
		}
		else if (info->map[ny][nx] == 'O')
		{
			if (get_diagonal_length(info->player.pos[X], \
				info->player.pos[Y], nx, ny) < 0.2)
				info->map[ny][nx] == '2';
		}
		i++;
	}
}

// int	press_key(int keycode, t_info *info)
// {
// 	if (keycode == KEY_W || keycode == KEY_A
// 		|| keycode == KEY_S || keycode == KEY_D)
// 		move(keycode, info);
// 	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
// 		rotate(keycode, info);
// 	// else if (keycode == KEY_SPACE)
// 	// 	open_door(info);
// 	display_3d(info);
// 	display_minimap(info);
// 	return (0);
// }

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
		info->ev.space = 1;
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
	if (keycode == KEY_SPACE)
		info->ev.space = 0;
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
	if ((info->ev.push_a && info->ev.push_w) || (info->ev.push_d && info->ev.push_w)
		|| (info->ev.push_a && info->ev.push_s) || (info->ev.push_d && info->ev.push_s))
		_move(info, 0.5);
	else if (info->ev.push_a || info->ev.push_w || info->ev.push_d || info->ev.push_s)
		_move(info, 1);
	if (info->ev.push_left)
		rotate(info, -1);
	else if (info->ev.push_right)
		rotate(info, 1);
	if (info->ev.space)
		open_door(info);
	if (info->is_opened)
	display_3d(info);
	display_minimap(info);
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, 3, 0, &release_key, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &press_close_button, info);
	mlx_loop_hook(info->mlx, &no_event, info);
}
