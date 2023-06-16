/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:32:42 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 22:47:47 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win, \
								game->images->ground, j * 64, i * 64);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->wall, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->player, j * 64, i * 64);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->exit, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->col, j * 64, i * 64);
		}
	}
}
