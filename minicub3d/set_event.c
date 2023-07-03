/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 19:58:43 by seojyang         ###   ########.fr       */
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
	int	move_x;
	int	move_y;

	move_x = 0;
	move_y = 0;
	if (keycode == 13 || keycode == 1)
		move_y = (keycode - 7) / 6;
	else
		move_x = keycode - 1;
	info->player.pos[Y] += move_y * SPEED;
	info->player.pos[X] += move_x * SPEED; // 혹시 뚝뚞 끊기면 어떻게 수정..?
	// 벽 뚫으면 어떻게..?
	display_3d(info);
}

// void	rotate(int keycode, t_info *info)
// {
	
// }

// void	open_door(t_info *info)
// {
	
// }

int	press_key(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move(keycode, info);
	// else if (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
	// 	rotate(keycode, info);
	// else if (keycode == KEY_SPACE)
	// 	open_door(info);
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->win, 2, 0, &press_key, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &press_close_button, info);
}
