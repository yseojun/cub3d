/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:47:50 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 22:40:23 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_arg_error(int argc, char *argv[])
{
	char	*file;
	int		len;

	if (argc != 2)
	{
		write(2, "Error\nArguments are not valid.\n", 31);
		return (1);
	}
	file = argv[1];
	len = ft_strlen(file);
	if (file[len - 4] != '.' || file[len - 3] != 'b' \
	|| file[len - 2] != 'e' || file[len - 1] != 'r')
	{
		write(2, "Error\nIt is not a BER file.\n", 28);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game		*game;

	if (find_arg_error(argc, argv))
		return (-1);
	game = set_game_data(argv);
	if (!game)
		return (-1);
	if (find_map_error(game))
	{
		free_game_data(game);
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, \
				game->map_width * 64, game->map_height * 64, "so_long");
	display_map(game);
	mlx_key_hook(game->win, &press_key, game);
	mlx_hook(game->win, CLOSE_BUTTON, 0, &press_close_button, game);
	mlx_loop(game->mlx);
	return (0);
}
