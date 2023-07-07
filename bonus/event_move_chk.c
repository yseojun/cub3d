/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_chk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:29 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 14:07:38 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	chk_move(t_info *info, double dpos_x, double dpos_y)
{
	char	target_x;
	char	target_y;

	target_x = info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)];
	target_y = info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
		[(int)info->player.pos[X]];
	if (target_x == '0' || target_x == 'O')
		info->player.pos[X] += dpos_x * SPEED;
	if (target_y == '0' || target_y == 'O')
		info->player.pos[Y] += dpos_y * SPEED;
}
