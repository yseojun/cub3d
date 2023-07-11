/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:56 by rolee             #+#    #+#             */
/*   Updated: 2023/07/11 14:02:55 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	free_str_arr(char **str_arr)
{
	int	idx;

	if (!str_arr)
		return ;
	idx = 0;
	while (str_arr[idx])
		free(str_arr[idx++]);
	free(str_arr);
}

int	str_arr_len(char **str_arr)
{
	int	idx;

	if (!str_arr)
		return (FAILURE);
	idx = 0;
	while (str_arr[idx])
		idx++;
	return (idx);
}

int	finish_game(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

int	occur_error(char *message)
{
	printf("ERROR: %s\n", message);
	return (EXIT_FAILURE);
}
