/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:52:25 by rolee             #+#    #+#             */
/*   Updated: 2023/07/04 18:18:43 by seojyang         ###   ########.fr       */
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
# define SUCCESS 0
# define FAILURE -1

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_SPACE 49
# define KEY_ESC 53
# define CLOSE_BUTTON 17

# define WIDTH 2000
# define HEIGHT 1000

# define WID 0
# define HEI 1
# define MINIMAP_ROOM 18
# define MINIMAP_DIVIER	2

# define X 0
# define Y 1
# define POV 1
# define SPEED 0.1
# define ANGLE 0.1

# define N 0
# define W 1
# define S 2
# define E 3

typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_player;

typedef struct s_draw
{
	int	from_x;
	int	from_y;
	int	to_x;
	int	to_y;
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
	double	perp_wall_dist;
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
	void			*mlx;
	void			*win;
	char			**map;
	int				map_size[2];
	struct s_img	frame;
	struct s_img	minimap;
	struct s_img	texture[4];
	int				f_color[3];
	int				c_color[3];
	t_player		player;
}	t_info;

t_info	set_info(char *path);
void	set_map_info(t_info *info, int fd);
void	check_valid_map(t_info info);
void	set_graphic_info(t_info *info, int fd);
void	set_player_info(t_info *info);

void	set_event(t_info *info);

void	free_str_arr(char **str_arr);
int		str_arr_len(char **str_arr);

t_draw	make_dr_info(int from_x, int fromY, int to_x, int to_y);
int		get_line_height(t_info *info, t_ray *ray);

t_ray	set_ray(t_info *info, int x);

void	display_3d(t_info *info);

void	set_frame(t_info *info, t_ray *ray, int x, int line_height);

#endif