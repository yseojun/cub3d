/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/06/19 18:53:12 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void put_color_info(int *color, char *clr)
{
	char	**spl;

	spl = ft_split(clr, ',');
	color[0] = ft_atoi(spl[0]);
	color[1] = ft_atoi(spl[1]);
	color[2] = ft_atoi(spl[2]);
}

int put_t_info(t_info *info, char *buffer)
{
	char	**spl;
	int		w;
	int		h;

	spl = ft_split(buffer, ' ');
	if (!ft_strncmp(spl[0], "NO", 3))
		info->no_texture = mlx_xpm_file_to_image(info->mlx, spl[1], &w, &h);
	else if (!ft_strncmp(spl[0], "SO", 3))
		info->so_texture = mlx_xpm_file_to_image(info->mlx, spl[1], &w, &h);
	else if (!ft_strncmp(spl[0], "WE", 3))
		info->we_texture = mlx_xpm_file_to_image(info->mlx, spl[1], &w, &h);
	else if (!ft_strncmp(spl[0], "EA", 3))
		info->ea_texture = mlx_xpm_file_to_image(info->mlx, spl[1], &w, &h);
	else if (!ft_strncmp(spl[0], "F", 2))
		put_color_info(info->f_color, spl[1]);
	else if (!ft_strncmp(spl[0], "C", 2))
		put_color_info(info->c_color, spl[1]);
	else
		return (-1);
	return (0);
}

char	**re_alloc(char **map, char *map_str)
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

char **set_map(int fd)
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
	map = re_alloc(map, map_str);
	while (map)
	{
		map_str = get_next_line(fd);
		if (!map_str)
			break ;
		map_str = ft_strtrim(map_str, "\n");
		map = re_alloc(map, map_str);
	}
	return (map);
}

t_player	make_player(int x, int y, char dir)
{
	t_player player;
	const int dx[4] = {0, 0, -1, 1};
	const int dy[4] = {1, -1, 0, 0};
	const char	dd[4] = {'N', 'S', 'W', 'E'};

	player.posX = x + 0.5;
	player.posY = y + 0.5;
	printf("posX: %f, posY: %f\n", player.posX, player.posY);
	int i = 0;
	while (i < 4)
	{
		if (dir == dd[i])
		{
			player.planeX = dx[i];
			player.planeY = dy[i];
			break ;
		}
		i++;
	}
	return (player);
}

void	set_player(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' || info->map[i][j] == 'W' || info->map[i][j] == 'E')
			{
				info->player = make_player(i, j, info->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

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
		if (put_t_info(&info, buffer) == 0)
			cnt++;
		else
			return info;
	}
	info.map = set_map(fd);
	set_player(&info);
	return (info);
}

void	display_map(t_info *info)
{
	int		i;
	int		j;
	
	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] != ' ')
				mlx_put_image_to_window(info->mlx, info->win, \
								info->so_texture, j * 64, i * 64);
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->win, \
								info->no_texture, j * 64, i * 64);
			if (info->map[i][j] == 'P')
				mlx_put_image_to_window(info->mlx, info->win, \
								info->we_texture, j * 64, i * 64);
		}
	}
}

void	display_player(t_info *info)
{
	int hit = 0;
	double	nowX;
	double	nowY;
	double	distX = 0;
	double	distY = 0;
	int color = 0x00FF0000;

	nowX = info->player.posX;
	nowY = info->player.posY;
	while (hit == 0)
	{
		mlx_pixel_put(info->mlx, info->win, lround(nowX), lround(nowY), color);
		nowX += info->player.planeX;
		distX += info->player.planeX;
		nowY += info->player.planeY;
		distY += info->player.planeY;
		if (info->map[lround(nowY)][lround(nowX)] == '1')
			hit = 1;
	}
}

int	main(int argc, char *argv[])
{
	t_info info;

	if (argc != 2)
		return (1);
	info = set_info(argv[1]);
	info.win = mlx_new_window(info.mlx, \
				1000, 2000, "so_long");
	display_map(&info);
	display_player(&info);
	mlx_loop(info.mlx);
	return (0);
}