/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:32:42 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 23:04:10 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_move_count(t_game *game)
{
	int			i;
	char		*move_cnt_str;

	i = 0;
	while (i < game->map_width)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
								game->images->ground, i * 64, 0);
		i++;
	}
	move_cnt_str = ft_itoa(game->move_cnt);
	mlx_string_put(game->mlx, game->win, 20, 37, 0x000000, "MOVE COUNT : ");
	mlx_string_put(game->mlx, game->win, 120, 37, 0x000000, move_cnt_str);
	free(move_cnt_str);
}

void	display_map_images(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->win, \
								game->images->ground, j * 64, i * 64 + 64);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->wall, j * 64, i * 64 + 64);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->exit, j * 64, i * 64 + 64);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->images->col, j * 64, i * 64 + 64);
			j++;
		}
		i++;
	}
}

void	display_player_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
						game->images->player[game->dir][game->move_cnt % 4], \
						j * 64, i * 64 + 64);
			j++;
		}
		i++;
	}
}

void	display_map(t_game	*game)
{
	display_move_count(game);
	display_map_images(game);
	display_player_image(game);
}
