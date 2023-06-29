/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/06/29 12:40:57 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

// void	display_map(t_info *info)
// {
// 	int		i;
// 	int		j;
	
// 	i = -1;
// 	while (info->map[++i])
// 	{
// 		j = -1;
// 		while (info->map[i][++j])
// 		{
// 			if (info->map[i][j] != ' ')
// 				mlx_put_image_to_window(info->mlx, info->win, \
// 								info->so_texture, j * 64, i * 64);
// 			if (info->map[i][j] == '1')
// 				mlx_put_image_to_window(info->mlx, info->win, \
// 								info->no_texture, j * 64, i * 64);
// 			if (info->map[i][j] == 'P')
// 				mlx_put_image_to_window(info->mlx, info->win, \
// 								info->we_texture, j * 64, i * 64);
// 		}
// 	}
// }

// void	display_player(t_info *info)
// {
// 	int hit = 0;
// 	double	nowX;
// 	double	nowY;
// 	double	distX = 0;
// 	double	distY = 0;
// 	t_draw dr;

// 	nowX = info->player.posX;
// 	nowY = info->player.posY;
// 	while (hit == 0)
// 	{
// 		nowX += info->player.planeX;
// 		distX += info->player.planeX;
// 		nowY += info->player.planeY;
// 		distY += info->player.planeY;
// 		if (info->map[(int)nowY][(int)nowX] == '1')
// 			hit = 1;
// 	}
// 	dr = make_dr_info(info->player.posX * 64, info->player.posY * 64, nowX * 64, nowY * 64);
// 	bresenham(info, dr);
// }

void	draw_line(t_info *info, t_ray *ray, int x, int line_height)
{
	int		start;
	int		end;
	int		color;
	t_draw	dr;
	
	color = 0xFF0000;
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	if (ray->side == X)
		color /= 2;
	dr = make_dr_info(x, start, x, end);
	bresenham(info, dr);
}

void	display_3d(t_info *info)
{
	t_ray	ray;
	int		x;
	int		line_height;

	x = 0;
	while (x < WIDTH)
	{	
		ray = set_ray(info, x);
		line_height = get_line_height(info, &ray);
		printf("x: %d, h: %d ", x, line_height);
		draw_line(info, &ray, x, line_height);
		x++;
	}
}

int a = 0xFF0000;

int	main(int argc, char *argv[])
{
	t_info info;

	if (argc != 2)
		return (1);
	info = set_info(argv[1]);
	info.win = mlx_new_window(info.mlx, \
				WIDTH, HEIGHT, "so_long");
	display_3d(&info);
	// display_map(&info);
	// display_player(&info);
	mlx_loop(info.mlx);
	return (0);
}