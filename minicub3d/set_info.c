/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/06/23 20:23:04 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

t_info set_info(char *path)
{
	t_info info;
	int 	fd;
	int 	cnt;
	char	*buffer;
	
	fd = open(path, O_RDONLY);
	info.mlx = mlx_init();
	if (fd < 0)
		exit(1);
	cnt = 0;
	while (cnt < 6)
	{
		buffer = get_next_line(fd);
		if (buffer == 0)
			return info;
		if (!ft_strncmp(buffer, "\n", 2))
			continue ;
		buffer = ft_strtrim(buffer, "\n"); //leak check!!!
		if (put_texture_info(&info, buffer) == 0)
			cnt++;
		else
			return info;
	}
	info.map = set_map(fd);
	set_player(&info);
	return (info);
}
