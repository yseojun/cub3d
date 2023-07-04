/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_graphic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:34:33 by rolee             #+#    #+#             */
/*   Updated: 2023/07/04 17:18:33 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void		put_texture_info(t_info *info, char *buffer);
static t_img	load_to_image(t_info *info, char *buffer);
static void		put_color_info(int *color, char *clr);

void	set_graphic_info(t_info *info, int fd)
{
	int		cnt;
	char	*buffer;

	cnt = 0;
	while (cnt < 6)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
	free_str_arr(spl);
}

static t_img	load_to_image(t_info *info, char *buffer)
{
	t_img	new;

	new.img = mlx_xpm_file_to_image(info->mlx, buffer, &new.width, &new.height);
	new.addr = mlx_get_data_addr(new.img, &new.bits, \
		&new.line_length, &new.endian);
	return (new);
}

static void	put_color_info(int *color, char *clr)
{
	char	**spl;

	spl = ft_split(clr, ',');
	if (str_arr_len(spl) != 3)
		exit(EXIT_FAILURE);
	color[0] = ft_atoi(spl[0]);
	color[1] = ft_atoi(spl[1]);
	color[2] = ft_atoi(spl[2]);
	if (color[0] < 0 || 255 < color[0] || color[1] < 0 || 255 < color[1]
		|| color[2] < 0 || 255 < color[2])
		exit(EXIT_FAILURE);
	free_str_arr(spl);
}
