/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_sprites_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:00:00 by rolee             #+#    #+#             */
/*   Updated: 2023/07/05 14:04:34 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static t_sprite	*sprites_realloc(t_info *info, int y, int x, char *file);

void	set_sprites(t_info *info)
{
	int	i;
	int	j;

	info->sprite_cnt = 0;
	info->sprites = NULL;
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '3')
				info->sprites = sprites_realloc(info, i, j, "./textures/cat_idle_animated_sprite.xpm");
			j++;
		}
		i++;
	}
}

static t_sprite	*sprites_realloc(t_info *info, int y, int x, char *file)
{
	t_sprite	*new_sprites;
	t_sprite	new_sprite;
	int			idx;

	new_sprite.pos[X] = x + 0.5;
	new_sprite.pos[Y] = y + 0.5;
	new_sprite.textrue = mlx_xpm_file_to_image(info->mlx, file, 
		&new_sprite.size[WID], &new_sprite.size[HEI]);
	if (!new_sprite.textrue)
		exit(EXIT_FAILURE);
	new_sprites = (t_sprite *)malloc(sizeof(t_sprite) * (info->sprite_cnt + 1));
	new_sprites[info->sprite_cnt] = new_sprite;
	idx = info->sprite_cnt - 1;
	while (idx >= 0)
	{
		new_sprites[idx] = info->sprites[idx];
		idx--;
	}
	if(info->sprites)
		free(info->sprites);
	info->sprite_cnt++;
	return (new_sprites);
}
