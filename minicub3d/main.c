/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/07/03 16:07:52 by seojyang         ###   ########.fr       */
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

int	get_tex_x(t_info *info, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == X)
		wall_x = info->player.pos[Y] + ray->perpWallDist * ray->ray_dir[Y];
	else
		wall_x = info->player.pos[X] + ray->perpWallDist * ray->ray_dir[X];
	wall_x -= floor(wall_x);

	tex_x = (int)(wall_x * (double)info->texture[ray->dir].width);
	if (ray->side == X && ray->ray_dir[X] > 0)
		tex_x = info->texture[ray->dir].width - tex_x - 1;
	if (ray->side == Y && ray->ray_dir[Y] < 0)
		tex_x = info->texture[ray->dir].width - tex_x - 1;
	return (tex_x);
}

void	draw_x_frame(t_info *info, t_ray *ray, int x, int line_height)
{
	double			step;
	double			tex_pos;
	int				tex_y;
	int				y;
	unsigned int	color;
	char			*dst;

	step = 1.0 * info->texture[ray->dir].height / line_height;
	tex_pos = (ray->start - HEIGHT / 2 + line_height / 2) * step;
	y = ray->start;
	int		*tx = (int *)info->texture[ray->dir].addr;
	while (y < ray->end)
	{
		tex_y = (int)tex_pos & (info->texture[ray->dir].height - 1);
		tex_pos += step;
		int idx = info->texture[ray->dir].height * tex_y + get_tex_x(info, ray);
		color = tx[idx];
		if (ray->side == Y)
			color = (color >> 1) & 8355711;
		// info->frame.addr[y * WIDTH + x] = color;
		dst = info->frame.addr + y * info->frame.line_length
			+ x * (info->frame.bits / 8);
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
	ray->dir = get_directrion(ray);
	draw_x_frame(info, ray, x, line_height);
}

void	display_3d(t_info *info)
{
	t_ray	ray;
	int		x;
	int		line_height;

	x = 0;
	info->frame.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->frame.addr = mlx_get_data_addr(info->frame.img, &info->frame.bits, \
		&info->frame.line_length, &info->frame.endian);
	while (x < WIDTH)
	{	
		ray = set_ray(info, x);
		line_height = get_line_height(info, &ray);
		// draw_line(info, &ray, x, line_height);
		set_frame(info, &ray, x, line_height);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img, 0, 0);
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
