NAME					:= push_swap
CC        		:= gcc
FLAGS 				:= -Wall -Wextra -Werror -g -fsanitize=address
LIBPUSH_SWAP 	:= libpush_swap
LIBFT					:= $(LIBPUSH_SWAP).a
GET_NEXT_LINE := get_next_line
CHECKER 			:= checker
LIBRARY 			:= -L./libpush_swap -lpush_swap
SRCS        	:= srcs/push_swap.c \
									srcs/arguments.c \
									srcs/printers.c \
									srcs/argument_checkers.c \
									srcs/initialise.c \
									srcs/initialise_stacks.c \
									srcs/node_utilities.c \
									srcs/stack_utilities.c \
									srcs/stack_utilities2.c \
									srcs/search_functions.c \
									srcs/operations.c \
									srcs/push_and_swap_operations.c \
									srcs/sort_three_four_five.c \
									srcs/cost_sort.c \
									srcs/cost_sort_utilities.c \
									srcs/sort_utilities.c \
									srcs/stack_resets.c \
									srcs/some_internet_sort.c \
									srcs/some_internet_sort_utilities.c \

CHECKER_SRCS := push_swap_checker/checker.c \
                push_swap_checker/read_and_run_operations.c \
                srcs/argument_checkers.c \
                srcs/arguments.c \
								srcs/cost_sort_utilities.c \
								srcs/initialise.c \
								srcs/initialise_stacks.c \
								srcs/node_utilities.c \
								srcs/printers.c \
								srcs/operations.c \
								srcs/push_and_swap_operations.c \
								srcs/search_functions.c \
								srcs/sort_utilities.c \
								srcs/stack_resets.c \
								srcs/stack_utilities.c \
								srcs/stack_utilities2.c \
                ${GET_NEXT_LINE}/get_next_line.c \
                ${GET_NEXT_LINE}/get_next_line_utils.c


OBJS        	:= $(SRCS:.c=.o)
CHECKER_OBJS	:= ${CHECKER_SRCS:.c=.o}

INCLUDES 			:= -I./includes/

CLR_RMV				:= \033[0m
RED		    		:= \033[1;31m
GREEN					:= \033[1;32m
YELLOW				:= \033[1;33m
BLUE					:= \033[1;34m
CYAN 					:= \033[1;36m
RM		    		:= rm -f

.PHONY:		all clean fclean re re_bonus

all:		${NAME}

bonus:		$(CHECKER)

${LIBFT}:
	@${MAKE} -C ./$(LIBPUSH_SWAP) --no-print-directory -s

${NAME}: $(LIBFT) ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} -o ${NAME}
	@echo "$(GREEN)$(NAME) created$(CLR_RMV)"

$(CHECKER): ${LIBFT} ${CHECKER_OBJS}
	@${CC} ${FLAGS} ${CHECKER_OBJS} ${INCLUDES} ${LIBRARY} -o ${CHECKER}
	@echo "$(GREEN)$(CHECKER) created$(CLR_RMV)"

%.o: %.c
	@gcc $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

${CHECKER}/%.o: ${CHECKER}/%.c
	@gcc $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@${RM} *.o */*.o */*/*.o
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)object files"

fclean:		clean
	@${RM} ${NAME}
	@${RM} ${CHECKER}
	@${MAKE} -C ./${LIBPUSH_SWAP} fclean --no-print-directory
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)"

re:			fclean all

re_bonus: fclean bonus
