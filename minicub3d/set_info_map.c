/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:34:03 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/03 15:24:52 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void put_color_info(int *color, char *clr)
{
	char	**spl;

	spl = ft_split(clr, ',');
	color[0] = ft_atoi(spl[0]);
	color[1] = ft_atoi(spl[1]);
	color[2] = ft_atoi(spl[2]);
}

t_img	load_to_image(t_info *info, char *buffer)
{
	t_img	new;

	new.img = mlx_xpm_file_to_image(info->mlx, buffer, &new.width, &new.height);
	new.addr = mlx_get_data_addr(new.img, &new.bits, \
		&new.line_length, &new.endian);
	return (new);
}

int put_texture_info(t_info *info, char *buffer)
{
	char	**spl;

	spl = ft_split(buffer, ' ');
	if (!ft_strncmp(spl[0], "NO", 3))
		info->texture[N] = load_to_image(info, spl[1]);
	else if (!ft_strncmp(spl[0], "WE", 3))
		info->texture[W] = load_to_image(info, spl[1]);
	else if (!ft_strncmp(spl[0], "SO", 3))
		info->texture[S] = load_to_image(info, spl[1]);
	else if (!ft_strncmp(spl[0], "EA", 3))
		info->texture[E] = load_to_image(info, spl[1]);
	else if (!ft_strncmp(spl[0], "F", 2))
		put_color_info(info->f_color, spl[1]);
	else if (!ft_strncmp(spl[0], "C", 2))
		put_color_info(info->c_color, spl[1]);
	else
		return (-1);
	return (0);
}

static char	**map_re_alloc(char **map, char *map_str)
{
	char	**new;
	int 	h;

	h = 0;
	if (map)
	{
		while (map[h])
			h++;
	}
	new = (char **)malloc(sizeof(char *) * (h + 2));
	new[h + 1] = 0;
	new[h] = ft_strdup(map_str);
	while (h > 0)
	{
		new[h - 1] = ft_strdup(map[h - 1]);
		h--;
	}
	// free_arr(map); // ㅁㅏㄴ드ㄹ기
	return (new);
}

char	**set_map(int fd)
{
	char *map_str;
	char **map;

	map = 0;
	while (1)
	{
		map_str = get_next_line(fd);
		if (ft_strncmp(map_str, "\n", 2))
			break ;
	}
	map_str = ft_strtrim(map_str, "\n");
	map = map_re_alloc(map, map_str);
	while (map)
	{
		map_str = get_next_line(fd);
		if (!map_str)
			break ;
		map_str = ft_strtrim(map_str, "\n");
		map = map_re_alloc(map, map_str);
	}
	return (map);
}
