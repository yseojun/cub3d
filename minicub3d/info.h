/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:52:25 by rolee             #+#    #+#             */
/*   Updated: 2023/07/03 16:51:12 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "../gnl/get_next_line_bonus.h"
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define CLOSE_BUTTON 17
# define WIDTH 2000
# define HEIGHT 1000
# define X 0
# define Y 1
# define POV 1
# define N 0
# define W 1
# define S 2
# define E 3

typedef struct s_player
{
	double pos[2];
	double dir[2];
	double plane[2];
} t_player;

typedef struct s_draw
{
	int	fromX;
	int	fromY;
	int	toX;
	int	toY;
	int	dx;
	int	dy;
	int	f;
	int	df_1;
	int	df_2;
}	t_draw;

typedef struct s_ray
{
	double	ray_dir[2];
	int		hit[2];
	int		step[2];
	double	delta_dist[2];
	double	side_dist[2];
	int		side;
	double	perpWallDist;
	int		dir;
	int		start;
	int		end;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		endian;
	int		bits;
	int		line_length;
	int		height;
	int		width;
}	t_img;

typedef struct s_tex_info
{
	int		*texture_int;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_tex_info;

typedef struct s_info
{
	struct s_img	frame;
	struct s_img	texture[4];
	char			**map;
	void			*mlx;
	void			*win;
	int				f_color[3];
	int				c_color[3];
	t_player		player;
}	t_info;

t_info	set_info(char *path);
char	**set_map(int fd);
int 	put_texture_info(t_info *info, char *buffer);
void	set_player(t_info *info);

t_draw	make_dr_info(int fromX, int fromY, int toX, int toY);
int		get_line_height(t_info *info, t_ray *ray);

t_ray	set_ray(t_info *info, int x);

void	display_3d(t_info *info);

void	set_frame(t_info *info, t_ray *ray, int x, int line_height);

#endif