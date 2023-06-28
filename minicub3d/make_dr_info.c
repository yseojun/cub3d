/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dr_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:10:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/06/28 14:23:10 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

t_draw	make_dr_info(int fromX, int fromY, int toX, int toY)
{
	t_draw	new;

	new.dx = abs(toX - fromX);
	new.dy = abs(toY - fromY);
	new.df_1 = 2 * new.dy;
	new.df_2 = 2 * (new.dy - new.dx);
	if (((!new.dx || new.dy / new.dx > 1) && fromY > toY)
		|| ((!new.dx || new.dy / new.dx <= 1) && fromX > toX))
	{
		new.fromX = toX;
		new.toX = fromX;
		new.fromY = toY;
		new.toY = fromY;
	}
	else
	{
		new.fromX = fromX;
		new.toX = toX;
		new.fromY = fromY;
		new.toY = toY;
	}
	return (new);
}
