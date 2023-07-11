/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:36:50 by rolee             #+#    #+#             */
/*   Updated: 2023/07/11 16:14:44 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	get_sprite_distance(t_info *info);
static void	sort_sprites(t_info *info);
static void	calculate_sprite(t_info *info, t_sprite_info *spr, int i);

void	display_sprites(t_info *info)
{
	t_sprite_info	spr;
	int				i;

	get_sprite_distance(info);
	sort_sprites(info);
	i = 0;
	while (i < info->sprite_cnt)
	{
		calculate_sprite(info, &spr, i);
		display_each_sprite(info, spr, i);
		i++;
	}
}

static void	calculate_sprite(t_info *info, t_sprite_info *spr, int i)
{
	spr->each = &info->sprites[i];
	spr->sprite[X] = spr->each->pos[X] - info->player.pos[X];
	spr->sprite[Y] = spr->each->pos[Y] - info->player.pos[Y];
	// 카메라 매트릭스의 역수?
	// 스프라이트의 방향이 플레이어를 기준으로 회전한 것처럼 보이게 하기 위해 필요하다?
	spr->inv_det = 1.0 / (info->player.plane[X] * info->player.dir[Y]
			- info->player.plane[Y] * info->player.dir[X]);
	spr->transform[X] = spr->inv_det * (info->player.dir[Y] * spr->sprite[X]
			- info->player.dir[X] * spr->sprite[Y]);
	spr->transform[Y] = spr->inv_det * (info->player.plane[X] * spr->sprite[Y]
			- info->player.plane[Y] * spr->sprite[X]); // 화면의 깊이?
	// 화면 상에서 스프라이트의 x 위치
	spr->sprite_screen_x = (int)((WIDTH / 2)
			* (1 + spr->transform[X] / spr->transform[Y]));
	// 화면에서 스프라이트의 높이
	spr->sprite_height = abs((int)(HEIGHT / spr->transform[Y]));
	// Y의 drawstart 및 end 계산
	spr->drawstart[Y] = -spr->sprite_height / 2 + HEIGHT / 2;
	if (spr->drawstart[Y] < 0)
		spr->drawstart[Y] = 0;
	spr->drawend[Y] = spr->sprite_height / 2 + HEIGHT / 2;
	if (spr->drawend[Y] >= HEIGHT)
		spr->drawend[Y] = HEIGHT - 1;
	// 화면에서 스프라이트의 너비
	spr->sprite_width = abs((int)(HEIGHT / spr->transform[Y]));
	// X의 drawstart 및 end 계산
	spr->drawstart[X] = -spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->drawstart[X] < 0)
		spr->drawstart[X] = 0;
	spr->drawend[X] = spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->drawend[X] >= WIDTH)
		spr->drawend[X] = WIDTH - 1;
}

static void	get_sprite_distance(t_info *info)
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

static void	sort_sprites(t_info *info)
{
	int			i;
	int			j;
	t_sprite	temp;
	
	i = 0;
	while (i < info->sprite_cnt - 1)
	{
		j = 0;
		while (j < info->sprite_cnt - 1 - i)
		{
			if (info->sprites[j].distance < info->sprites[j + 1].distance)
			{
				temp = info->sprites[j];
				info->sprites[j] = info->sprites[j + 1];
				info->sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
