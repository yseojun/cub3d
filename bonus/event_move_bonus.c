/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:08:46 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/05 16:39:43 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	move_up(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = info->player.dir[X] * val;
	dpos_y = info->player.dir[Y] * val;
	if (info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)] == '0')
		info->player.pos[X] += dpos_x * SPEED;
	if (info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
		[(int)info->player.pos[X]] == '0')
		info->player.pos[Y] += dpos_y * SPEED;
}

void	move_down(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = -info->player.dir[X] * val;
	dpos_y = -info->player.dir[Y] * val;
	if (info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)] == '0')
		info->player.pos[X] += dpos_x * SPEED;
	if (info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
		[(int)info->player.pos[X]] == '0')
		info->player.pos[Y] += dpos_y * SPEED;
}

void	move_left(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = info->player.dir[Y] * val;
	dpos_y = -info->player.dir[X] * val;

	if (info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)] == '0')
		info->player.pos[X] += dpos_x * SPEED;
	if (info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
		[(int)info->player.pos[X]] == '0')
		info->player.pos[Y] += dpos_y * SPEED;
}

void	move_right(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = -info->player.dir[Y] * val;
	dpos_y = info->player.dir[X] * val;
	if (info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)] == '0')
		info->player.pos[X] += dpos_x * SPEED;
	if (info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
		[(int)info->player.pos[X]] == '0')
		info->player.pos[Y] += dpos_y * SPEED;
}
