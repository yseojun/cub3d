/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:56 by rolee             #+#    #+#             */
/*   Updated: 2023/07/05 15:28:35 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

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
