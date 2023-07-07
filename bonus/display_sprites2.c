/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:47:03 by rolee             #+#    #+#             */
/*   Updated: 2023/07/07 18:54:12 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	get_sprite_distance(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->sprite_cnt)
	{
		info->sprites[idx].distance = get_distance(
				info->player.pos[X], info->player.pos[Y],
				info->sprites[idx].pos[X], info->sprites[idx].pos[Y]);
		idx++;
	}
}
