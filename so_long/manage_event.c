/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:16:52 by rolee             #+#    #+#             */
/*   Updated: 2023/01/18 09:04:35 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear(t_game *game)
{
	write(1, "Clear the game in ", 18);
	ft_putnbr_fd(game->move_cnt, 1);
	write(1, " moves!\n", 8);
	mlx_destroy_window(game->mlx, game->win);
	free_game_data(game);
	exit(0);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_game_data(game);
		exit(0);
	}
	return (0);
}

int	press_close_button(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game_data(game);
	exit(0);
}
