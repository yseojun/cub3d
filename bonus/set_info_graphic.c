/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_graphic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:34:33 by rolee             #+#    #+#             */
/*   Updated: 2023/07/11 13:48:05 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void		put_texture_info(t_info *info, char *buffer);
static void		put_color_info(int *color, char *clr);

void	set_graphic_info(t_info *info, int fd)
{
	int		cnt;
	char	*buffer;

	info->texture[DOOR] = load_to_image(info, DOOR_FILE_PATH);
	cnt = 0;
	while (cnt < 6)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			exit(occur_error("Invalid File: not enough information."));
		if (!ft_strncmp(buffer, "\n", 2))
			continue ;
		buffer = ft_strtrim(buffer, "\n");
		put_texture_info(info, buffer);
		free(buffer);
		cnt++;
	}
}

static void	put_texture_info(t_info *info, char *buffer)
{
	char	**spl;

	spl = ft_split(buffer, ' ');
	if (str_arr_len(spl) != 2)
		exit(occur_error("Invalid File: wrong texture infomation."));
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
		exit(occur_error("Invalid File: unnecessary content."));
	free_str_arr(spl);
}

// 이거 뭔가 다른 파일로 옮기고 싶은데
t_img	load_to_image(t_info *info, char *file)
{
	t_img	new;

	new.img = mlx_xpm_file_to_image(info->mlx, file, &new.width, &new.height);
	if (!new.img)
		exit(occur_error("Invalid File: wrong texture file."));
	new.addr = mlx_get_data_addr(new.img, &new.bits, \
		&new.line_length, &new.endian);
	return (new);
}

static void	put_color_info(int *color, char *clr)
{
	char	**spl;

	spl = ft_split(clr, ',');
	if (str_arr_len(spl) != 3)
		exit(occur_error("Invalid File: wrong color infomation."));
	color[0] = ft_atoi(spl[0]);
	color[1] = ft_atoi(spl[1]);
	color[2] = ft_atoi(spl[2]);
	if (color[0] < 0 || 255 < color[0] || color[1] < 0 || 255 < color[1]
		|| color[2] < 0 || 255 < color[2])
		exit(occur_error("Invalid File: rgb value out of range."));
	free_str_arr(spl);
}
