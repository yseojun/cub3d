/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:23:11 by rolee             #+#    #+#             */
/*   Updated: 2023/07/07 18:23:43 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static t_sprite	*sprites_realloc(t_info *info, int y, int x);
static	void	set_sprite_frames(t_info *info, t_sprite *sprite);

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
				info->sprites = sprites_realloc(info, i, j);
			j++;
		}
		i++;
	}
}

static t_sprite	*sprites_realloc(t_info *info, int y, int x)
{
	t_sprite	*new_sprites;
	t_sprite	new_sprite;
	int			idx;

	new_sprite.pos[X] = x + 0.5;
	new_sprite.pos[Y] = y + 0.5;
	set_sprite_frames(info, &new_sprite);
	new_sprites = (t_sprite *)malloc(sizeof(t_sprite) * (info->sprite_cnt + 1));
	new_sprites[info->sprite_cnt] = new_sprite;
	idx = info->sprite_cnt - 1;
	while (idx >= 0)
	{
		new_sprites[idx] = info->sprites[idx];
		idx--;
	}
	if (info->sprites)
		free(info->sprites);
	info->sprite_cnt++;
	return (new_sprites);
}

static	void	set_sprite_frames(t_info *info, t_sprite *sprite)
{
	int		idx;
	char	*file_name;
	char	*total_name;

	idx = 0;
	while (idx < 4)
	{
		file_name = ft_strjoin("./textures/mew_idle/mew_idle00", ft_itoa(idx));
		total_name = ft_strjoin(file_name, ".xpm");
		free(file_name);
		sprite->frame[idx] = load_to_image(info, total_name);
		free(total_name);
		idx++;
	}
}
