/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:11:15 by rolee             #+#    #+#             */
/*   Updated: 2023/01/18 09:55:31 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_file_path(int dir, int idx)
{
	char	*temp;
	char	*idx_str;
	char	*file_path;

	idx_str = ft_itoa(idx);
	if (dir == 0)
		temp = ft_strjoin(PLAYER_DOWN, idx_str);
	if (dir == 1)
		temp = ft_strjoin(PLAYER_LEFT, idx_str);
	if (dir == 2)
		temp = ft_strjoin(PLAYER_UP, idx_str);
	if (dir == 3)
		temp = ft_strjoin(PLAYER_RIGHT, idx_str);
	free(idx_str);
	if (!temp)
		return (NULL);
	file_path = ft_strjoin(temp, ".xpm");
	free(temp);
	if (!file_path)
		return (NULL);
	return (file_path);
}

void	set_player_image_data(t_game *game, t_images *images, int w, int h)
{
	int		i;
	int		j;
	char	*file;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			file = get_file_path(i, j);
			images->player[i][j] = \
					mlx_xpm_file_to_image(game->mlx, file, &w, &h);
			free(file);
			j++;
		}
		i++;
	}
}

t_images	*set_image_data(t_game *game)
{
	t_images	*images;
	int			width;
	int			height;

	images = (t_images *)malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	images->col = mlx_xpm_file_to_image(game->mlx, COL, &width, &height);
	images->wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	images->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
	images->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &width, &height);
	set_player_image_data(game, images, width, height);
	return (images);
}

t_game	*set_game_data(char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = set_map(argv, &game->total_col_cnt);
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	game->mlx = mlx_init();
	game->images = set_image_data(game);
	if (!game->images)
	{
		free_map(game->map);
		free(game);
		return (NULL);
	}
	game->map_width = 0;
	game->map_height = 0;
	game->cur_col_cnt = 0;
	game->move_cnt = 0;
	game->dir = DOWN;
	return (game);
}
