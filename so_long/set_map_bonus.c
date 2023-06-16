/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:38:55 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 23:02:25 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_map_str(int fd, char *buffer)
{
	int		read_byte;
	char	*map_str;
	char	*temp;

	while (1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		if (read_byte == 0)
		{
			if (!map_str)
				write(2, "Error\nFile is empty.\n", 21);
			break ;
		}
		if (!map_str)
			map_str = ft_strdup("");
		buffer[read_byte] = 0;
		temp = map_str;
		map_str = ft_strjoin(temp, buffer);
		free(temp);
		if (!map_str)
			return (NULL);
	}
	return (map_str);
}

char	*get_map_str(char *argv[])
{
	int		fd;
	char	*buffer;
	char	*map_str;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		write(2, "Error\nFile cannot be read.\n", 27);
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	map_str = read_map_str(fd, buffer);
	close(fd);
	free(buffer);
	if (!map_str)
		return (NULL);
	return (map_str);
}

char	**set_map(char *argv[], int *total_col_cnt)
{
	char	*map_str;
	char	**map;

	map_str = get_map_str(argv);
	if (!map_str)
		return (NULL);
	if (find_newline_error(map_str))
	{
		free(map_str);
		write(2, "Error\nMap has invalid newline.\n", 31);
		return (NULL);
	}
	if (find_component_error(map_str, total_col_cnt))
	{
		free(map_str);
		write(2, "Error\nMap has invaild components.\n", 34);
		return (NULL);
	}
	map = ft_split(map_str);
	free(map_str);
	if (!map)
		return (NULL);
	return (map);
}
