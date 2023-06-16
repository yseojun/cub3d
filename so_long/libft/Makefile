NAME = libft.a

SRCS = ft_itoa.c ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
