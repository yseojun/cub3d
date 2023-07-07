NAME = cub3d

SRCS = main.c \
utils.c \
set_info.c \
set_info_graphic.c \
set_info_map.c \
check_valid_map.c \
set_info_player.c \
make_dr_info.c \
get_line_height.c \
set_ray.c \
display_3d.c \
draw_line.c \
set_frame.c \
set_event.c
BONUS_SRCS = main.c \
utils.c \
set_info.c \
set_info_graphic.c \
set_info_map.c \
check_valid_map.c \
set_info_player.c \
make_dr_info.c \
get_line_height.c \
set_ray.c \
display_3d.c \
display_minimap.c \
draw_line.c \
set_frame.c \
set_event.c \
set_mouse_bonus.c \
event_move_bonus.c \
manage_door.c \
event_move_chk.c
OBJS = $(addprefix mandatory/, $(SRCS:.c=.o))\
	$(GNL:.c=.o)
BONUS_OBJS = $(addprefix bonus/, $(BONUS_SRCS:.c=.o))\
	$(GNL:.c=.o)

GNL = gnl/get_next_line_bonus.c \
gnl/get_next_line_utils_bonus.c

CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g


all : $(NAME)

$(NAME): $(OBJS)
	make -C libft all -j6
	make -C mlx all -j6
	$(CC) $(FLAGS) $^ libft/libft.a -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

bonus : $(BONUS_OBJS)
	make -C libft all -j6
	make -C mlx all -j6
	$(CC) $(FLAGS) $^ libft/libft.a -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	make -C libft clean
	make -C mlx clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus