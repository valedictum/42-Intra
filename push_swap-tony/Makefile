NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE =	operation/*.c \
			sorting/*.c \
			main.c \
			error.c \
			push_swap.c \
			util.c \
			ft_split.c

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -I. -o $(NAME)

all: $(NAME)

clean:
	rm -rf *.o
	rm -rf operation/*.o
	rm -rf sorting/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re