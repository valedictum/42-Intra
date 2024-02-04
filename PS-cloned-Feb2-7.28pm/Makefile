# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:44:36 by atang             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/02/04 19:12:13 by atang            ###   ########.fr        #
=======
#    Updated: 2024/01/28 16:45:59 by atang            ###   ########.fr        #
>>>>>>> 13dc9cfb5c88955113a0eccd975d47c39b4a44a5
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
RM 				= rm -f
CFLAGS 			= -fsanitize=address -Wall -Wextra -Werror -I$(PRINTF_DIR) -I$(INCS)
LIBRARY 		= -L$(PRINTF_DIR) -lftprintf

.SILENT:

ROOT_DIR 		= $(shell pwd)
PRINTF_DIR 		= $(ROOT_DIR)/libs/printf
SRC_DIR 		= $(ROOT_DIR)/srcs/push_swap

SRCS	= 	push_swap.c \
			chunk_utils.c \
			operations_push.c \
			operations_reverse_rotate.c \
			operations_rotate.c \
        	operations_swap.c \
           	parse_arguments.c \
           	ps_check_utils.c \
			ps_find_utils.c \
			ps_list_utils.c \
			ps_memory_utils.c \
			ps_print_utils.c \
			ps_split.c \
			rotate_to_top.c \
			sort_2_or_3_numbers.c \
			sort_5_numbers.c \
			sort_more_than_5_numbers.c \

OBJS	=	$(SRCS:.c=.o)

INCS = $(ROOT_DIR)/incs

$(NAME): all

all:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -I $(INCS) -I $(PRINTF_DIR) $(addprefix $(SRC_DIR)/, $(SRCS)) -o $(NAME) $(LIBRARY)

clean:
	$(RM) $(OBJS)

fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
