/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:53:30 by rolee             #+#    #+#             */
/*   Updated: 2023/01/18 09:55:16 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define CLOSE_BUTTON 17

# define COL "./textures/collectible.xpm"
# define WALL "./textures/wall.xpm"
# define EXIT "./textures/exit.xpm"
# define GROUND "./textures/background.xpm"
# define PLAYER_DOWN "./textures/player_down_"
# define PLAYER_LEFT "./textures/player_left_"
# define PLAYER_UP "./textures/player_up_"
# define PLAYER_RIGHT "./textures/player_right_"

# define DOWN 0
# define LEFT 1
# define UP 2
# define RIGHT 3

typedef struct s_images
{
	void	*col;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player[4][4];
}	t_images;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	int			total_col_cnt;
	int			cur_col_cnt;
	int			move_cnt;
	int			dir;
	t_images	*images;
	void		*mlx;
	void		*win;
}	t_game;

void	display_map(t_game	*game);
int		find_component_error(char *map_str, int *collectible_cnt);
int		find_newline_error(char *map_str);
int		find_map_error(t_game *game);
void	get_p_location(char **map, int *y, int *x);
int		find_vaild_path_error(t_game *game);
void	free_map(char **map);
void	free_game_data(t_game *game);
void	clear(t_game *game);
int		press_key(int keycode, t_game *game);
int		press_close_button(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_right(t_game *game);
t_game	*set_game_data(char *argv[]);
char	**set_map(char *argv[], int *total_col_cnt);

#endif