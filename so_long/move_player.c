/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:34:39 by rolee             #+#    #+#             */
/*   Updated: 2023/01/18 09:56:22 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game)
{
	int	y;
	int	x;

	get_p_location(game->map, &y, &x);
	if (game->map[y + 1][x] == 'E' && game->cur_col_cnt == game->total_col_cnt)
		clear(game);
	if (game->map[y + 1][x] == 'C' || game->map[y + 1][x] == '0')
	{
		if (game->map[y + 1][x] == 'C')
			game->cur_col_cnt++;
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->move_cnt++;
		game->dir = DOWN;
		ft_putnbr_fd(game->move_cnt, 1);
		write(1, " moves\n", 7);
		display_map(game);
	}
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	get_p_location(game->map, &y, &x);
	if (game->map[y][x - 1] == 'E' && game->cur_col_cnt == game->total_col_cnt)
		clear(game);
	if (game->map[y][x - 1] == 'C' || game->map[y][x - 1] == '0')
	{
		if (game->map[y][x - 1] == 'C')
			game->cur_col_cnt++;
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->move_cnt++;
		game->dir = LEFT;
		ft_putnbr_fd(game->move_cnt, 1);
		write(1, " moves\n", 7);
		display_map(game);
	}
}

void	move_up(t_game *game)
{
	int	y;
	int	x;

	get_p_location(game->map, &y, &x);
	if (game->map[y - 1][x] == 'E' && game->cur_col_cnt == game->total_col_cnt)
		clear(game);
	if (game->map[y - 1][x] == 'C' || game->map[y - 1][x] == '0')
	{
		if (game->map[y - 1][x] == 'C')
			game->cur_col_cnt++;
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->move_cnt++;
		game->dir = UP;
		ft_putnbr_fd(game->move_cnt, 1);
		write(1, " moves\n", 7);
		display_map(game);
	}
}

void	move_right(t_game *game)
{
	int	y;
	int	x;

	get_p_location(game->map, &y, &x);
	if (game->map[y][x + 1] == 'E' && game->cur_col_cnt == game->total_col_cnt)
		clear(game);
	if (game->map[y][x + 1] == 'C' || game->map[y][x + 1] == '0')
	{
		if (game->map[y][x + 1] == 'C')
			game->cur_col_cnt++;
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->move_cnt++;
		game->dir = RIGHT;
		ft_putnbr_fd(game->move_cnt, 1);
		write(1, " moves\n", 7);
		display_map(game);
	}
}
