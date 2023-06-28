/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:52:25 by rolee             #+#    #+#             */
/*   Updated: 2023/06/28 13:14:05 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

#include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "../gnl/get_next_line_bonus.h"
# include "../libft/libft.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define CLOSE_BUTTON 17

typedef struct s_player
{
	double posX;
	double posY;
	double planeX;
	double planeY;
} t_player;

typedef struct s_draw
{
	int	fromX;
	int fromY;
	int	toX;
	int toY;
	int dx;
	int dy;
	int f;
	int df_1;
	int df_2;
}	t_draw;

typedef struct s_info
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*no_texture;
	void		*so_texture;
	void		*we_texture;
	void		*ea_texture;
	int			f_color[3];
	int			c_color[3];
	t_player	player;
}	t_info;

t_info	set_info(char *path);
char	**set_map(int fd);
int 	put_texture_info(t_info *info, char *buffer);
void	set_player(t_info *info);

void bresenham(t_info *info, t_draw dr);
t_draw	make_dr_info(int fromX, int fromY, int toX, int toY);

#endif