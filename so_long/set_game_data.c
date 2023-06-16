/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:11:15 by rolee             #+#    #+#             */
/*   Updated: 2023/01/18 09:55:36 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	images->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &width, &height);
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
