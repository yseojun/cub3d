/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:52:35 by rolee             #+#    #+#             */
/*   Updated: 2023/01/12 15:49:04 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		free(map[idx]);
		idx++;
	}
	free(map);
}

void	free_game_data(t_game *game)
{
	free_map(game->map);
	free(game->images);
	free(game);
}
