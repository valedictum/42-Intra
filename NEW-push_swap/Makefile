# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:44:36 by atang             #+#    #+#              #
#    Updated: 2023/10/01 15:35:33 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror
LIBRARY 		= -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

ROOT_DIR 		= $(shell pwd)
LIBFT_DIR 		= $(ROOT_DIR)/libs/libft
PRINTF_DIR 		= $(ROOT_DIR)//libs/printf
SRCS	= srcs/push_swap/push_swap.c \
			calculate_ab.c \
			calculate_ba.c \
			operations_push.c \
			operations_reverse_rotate.c \
			operations_rotate.c \
        	operations_swap.c \
           	parse_arguments.c \
           	ps_check_utils.c \
           	ps_find_index_utils.c \
			ps_find_utils.c \
			ps_list_utils.c \
			ps_memory_utils.c \
			ps_print_utils.c \
			rotate_and_push_type.c \
			rotate_type.c \
			sort_few.c \
			sort_many.c \

INCS 			= ./incs

$(NAME): all

all:
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -I $(INCS) $(SRCS) -o $(NAME) $(LIBRARY)

clean:
	${RM} ${SRCS:.c=.o}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
