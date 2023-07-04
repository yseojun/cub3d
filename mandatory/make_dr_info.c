/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dr_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:10:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 17:31:37 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

t_draw	make_dr_info(int from_x, int from_y, int to_x, int to_y)
{
	t_draw	new;

	new.dx = abs(to_x - from_x);
	new.dy = abs(to_y - from_y);
	new.df_1 = 2 * new.dy;
	new.df_2 = 2 * (new.dy - new.dx);
	if (((!new.dx || new.dy / new.dx > 1) && from_y > to_y)
		|| ((!new.dx || new.dy / new.dx <= 1) && from_x > to_x))
	{
		new.from_x = to_x;
		new.to_x = from_x;
		new.from_y = to_y;
		new.to_y = from_y;
	}
	else
	{
		new.from_x = from_x;
		new.to_x = to_x;
		new.from_y = from_y;
		new.to_y = to_y;
	}
	return (new);
}
