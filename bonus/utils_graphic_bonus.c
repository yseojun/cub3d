/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:05:47 by rolee             #+#    #+#             */
/*   Updated: 2023/07/11 15:16:16 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

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

int	encode_rgb(int color[3])
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

// set_info_sprites.c 외에도 쓸 거면 type != 'O' 추가해야 할 지도
int	is_sprite(char type)
{
	return (type != '0' && type != ' ' && type != '1' && type != '2');
}
