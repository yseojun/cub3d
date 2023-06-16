NAME = so_long

SRCS = main.c set_game_data.c set_map.c find_map_error.c \
		find_vaild_path_error.c free_memory.c display_map.c \
		manage_event.c move_player.c
BONUS_SRCS = main_bonus.c set_game_data_bonus.c set_map_bonus.c \
		find_map_error_bonus.c find_vaild_path_error_bonus.c \
		free_memory_bonus.c display_map_bonus.c manage_event_bonus.c move_player_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1

$(NAME): $(OBJ_FILES)
	make -C libft all
	make -C mlx all
	$(CC) $(FLAGS) $(OBJ_FILES) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

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