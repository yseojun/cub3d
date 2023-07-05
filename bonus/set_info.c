/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/05 15:39:24 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

// static void	set_sprites(t_info *info);
// static t_sprite	*sprites_realloc(t_info *info, int y, int x, char *file);

t_info	set_info(char *path)
{
	t_info	info;
	int		fd;

	info.mlx = mlx_init();
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	set_graphic_info(&info, fd);
	set_map_info(&info, fd);
	check_valid_map(info);
	//set_sprites(&info);
	set_player_info(&info);
	return (info);
}

// static void	set_sprites(t_info *info)
// {
// 	int	i;
// 	int	j;

// 	info->sprite_cnt = 0;
// 	info->sprites = NULL;
// 	i = 0;
// 	while (info->map[i])
// 	{
// 		j = 0;
// 		while (info->map[i][j])
// 		{
// 			if (info->map[i][j] == '3')
// 				info->sprites = sprites_realloc(info, i, j, "./textures/bluestone.xpm");
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static t_sprite	*sprites_realloc(t_info *info, int y, int x, char *file)
// {
// 	t_sprite	*new_sprites;
// 	t_sprite	new_sprite;
// 	int			idx;

// 	new_sprite.pos[X] = x + 0.5;
// 	new_sprite.pos[Y] = y + 0.5;
// 	new_sprite.textrue = mlx_xpm_file_to_image(info->mlx, file, 
// 		&new_sprite.size[WID], &new_sprite.size[HEI]);
// 	if (!new_sprite.textrue)
// 		exit(EXIT_FAILURE);
// 	new_sprites = (t_sprite *)malloc(sizeof(t_sprite) * (info->sprite_cnt + 1));
// 	new_sprites[info->sprite_cnt] = new_sprite;
// 	idx = info->sprite_cnt - 1;
// 	while (idx >= 0)
// 	{
// 		new_sprites[idx] = info->sprites[idx];
// 		idx--;
// 	}
// 	if(info->sprites)
// 		free(info->sprites);
// 	info->sprite_cnt++;
// 	return (new_sprites);
// }
