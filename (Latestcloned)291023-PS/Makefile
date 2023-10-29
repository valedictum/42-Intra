# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:44:36 by atang             #+#    #+#              #
#    Updated: 2023/10/29 20:15:47 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror -I$(PRINTF_DIR) -I$(INCS)
LIBRARY 		= -L$(PRINTF_DIR) -lftprintf

ROOT_DIR 		= $(shell pwd)
PRINTF_DIR 		= $(ROOT_DIR)/libs/printf
SRC_DIR 		= $(ROOT_DIR)/srcs/push_swap

SRCS	= 	push_swap.c \
			operations_combinations.c \
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
			ps_split.c \
			sort_2_or_3_numbers.c \
			sort_4_or_5_numbers.c \
			sort_more_than_5_numbers.c \

OBJS	=	$(SRCS:.c=.o)

INCS = $(ROOT_DIR)/incs

$(NAME): all

all:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -I $(INCS) -I $(PRINTF_DIR) $(addprefix $(SRC_DIR)/, $(SRCS)) -o $(NAME) $(LIBRARY)

clean:
	${RM} ${SRCS:.c=.o}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
