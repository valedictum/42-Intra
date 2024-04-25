NAME = libpush_swap.a
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = $(shell find . -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
INCLUDE = -I../includes

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

#Background Colors:

BLACK_BG = \033[0;40m
RED_BG = \033[0;41m
GREEN_BG = \033[0;42m
YELLOW_BG = \033[0;43m
BLUE_BG = \033[0;44m
MAGENTA_BG = \033[0;45m
CYAN_BG = \033[0;46m
WHITE_BG = \033[0;47m

RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(patsubst %.c, %.o, $(SRCS))
	@echo "\n$(CYAN)Compiling Push_Swap Libft$(RESET)"
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
# @$(MAKE) clean -s
	@echo "$(GREEN)Compile Complete! Have fun!$(RESET)"

%.o: %.c
	@gcc $(FLAGS) -c $(INCLUDE) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf *.o
	@echo "$(BLUE)Output files ousted.$(RESET)"

fclean:
	@rm -rf $(NAME)
	@echo "$(MAGENTA)Liberated Libft.$(RESET)"

re: fclean all
