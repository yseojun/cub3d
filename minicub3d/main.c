/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/06/29 17:57:22 by seojyang         ###   ########.fr       */
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

int	get_directrion(t_ray *ray)
{
	if (ray->side == X)
	{
		if (ray->ray_dir[X] > 0)
			return (W);
		else
			return (E);
	}
	else
	{
		if (ray->ray_dir[Y] > 0)
			return (N);
		else
			return (S);
	}
}

int	get_tex_x(t_info *info, int x)
{
	double	wall_x;

	if (side == 0)
		wall_x = 
}

void	draw_x_frame(t_info *info, t_ray *ray, int x, int line_height)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		y;
	char	*dst;

	step = 1.0 * info->texture_h[ray->direction] / line_height;
	tex_pos = (ray->start - HEIGHT / 2 + line_height / 2) * step;
	y = ray->start;
	while (y < ray->end)
	{
		tex_y = (int)tex_pos & (info->texture_h[ray->direction] - 1);
		tex_pos = step;
		color = texture[ray->direction][info->texture_h[ray->direction]
			* tex_y + get_tex_x(info, x)];
		if (ray->side == Y)
			color = (color >> 1) & 8355711;
		dst = info->img.addr + y * info->img.line_length
			+ x * (info->img.bits / 8);
		*(unsigned int *)dst = color;
		y++;
	}
}

void	set_frame(t_info *info, t_ray *ray, int x, int line_height)
{
	ray->start = -line_height / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = line_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	ray->direction = get_directrion(ray);
	draw_x_frame(info, ray, x, line_height);
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
		// draw_line(info, &ray, x, line_height);
		set_frame(info, &ray, x, line_height);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

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
