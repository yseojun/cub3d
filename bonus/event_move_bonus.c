/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:08:46 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 14:07:12 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	move_up(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = info->player.dir[X] * val;
	dpos_y = info->player.dir[Y] * val;
	chk_move(info, dpos_x, dpos_y);
}

void	move_down(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = -info->player.dir[X] * val;
	dpos_y = -info->player.dir[Y] * val;
	chk_move(info, dpos_x, dpos_y);
}

void	move_left(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = info->player.dir[Y] * val;
	dpos_y = -info->player.dir[X] * val;
	chk_move(info, dpos_x, dpos_y);
}

void	move_right(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = -info->player.dir[Y] * val;
	dpos_y = info->player.dir[X] * val;
	chk_move(info, dpos_x, dpos_y);
}
