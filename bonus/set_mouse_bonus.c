/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:39:22 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 15:26:48 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	set_mouse(t_info *info)
{
	int	tmp;

	mlx_mouse_move(info->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_get_pos(info->win, &info->ev.prev_mouse_x, &tmp);
	mlx_mouse_hide();
}
