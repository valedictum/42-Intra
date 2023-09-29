# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:44:36 by atang             #+#    #+#              #
#    Updated: 2023/09/12 16:53:35 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
CC     	= gcc
CFLAGS 	= -Wall -Wextra -Werror
SRCS	= push_swap.c \
			ps_utils.c \
			ps_print_utils.c \
			sort_elements.c \
        	swap_operations.c \
           	push_operations.c \
           	rotate_operations.c \
           	reverse_rotate_operations.c

TEST_SRCS	= test_main.c

OBJS	=	$(SRCS:.c=.o)

RM       = rm -f

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: tet

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(PROGRAM) PS

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o PS test_main.c -I./includes -L./ -lpushswap

.PHONY: all clean fclean re
