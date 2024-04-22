.SILENT:

NAME = philo
CFLAGS = -Wall -Werror -Wextra

SRCS = philo.c \
     utils.c \
     time.c \
     initialize.c \
     control.c \
     routine.c \
     destory_and_free.c 

OBJS = $(patsubst %.c, %.o, $(SRCS))

GREEN = \033[32m
BLUE = \033[34m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME)
		echo "$(BLUE)Program compiled successfully$(END)"

clean:
		$(RM) $(OBJS)
		echo "$(GREEN)Removed object files$(END)"

fclean: clean
		$(RM) $(NAME)
		echo "$(GREEN)Removed executable$(END)"

re: fclean all

.PHONY:	all clean fclean re
