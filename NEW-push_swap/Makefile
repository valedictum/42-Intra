# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:44:36 by atang             #+#    #+#              #
#    Updated: 2023/09/29 22:19:39 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror
LIBRARY 		= -lft -lftprintf

ROOT_DIR 		= $(shell pwd)
LIBFT_DIR 		= $(ROOT_DIR)/lib/libft
PRINTF_DIR 		= $(ROOT_DIR)//lib/printf

SRCS 			= ./srcs/*.c
INCS 			= ./incs
LIBS 			= ./libs

/*
SRCS	= srcs/push_swap/push_swap.c \
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
			ps_sort_few.c \
			ps_sort_many.c \
*/

$(NAME): all

all:
	make -C $(LIBFTDIR)
	make -C $(FT_PRINTFDIR)
	$(CC) $(CFLAGS) -I $(INCS) $(SRCS) -o $(NAME) -L$(LIBFT_DIR0) -L$(PRINTF_DIR)

clean:
	${RM} ${LIBFT_DIR}/*.o
	${RM} ${PRINTF_DIR}/*.o

fclean:	clean
	${RM} ${LIBFT_DIR}/*.a
	${RM} ${PRINTF_DIR}/*.a
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
