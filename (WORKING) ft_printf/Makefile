# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 13:43:51 by atang             #+#    #+#              #
#    Updated: 2023/08/15 11:15:16 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   	= libftprintf.a

CC     	= gcc
CFLAGS 	= -Wall -Wextra -Werror
SRCS	= ft_character.c \
        	ft_hexadecimal.c \
           	ft_integer.c \
           	ft_pointer.c \
           	ft_printf.c \
           	ft_string.c \
           	ft_unsigned_decimal.c

TEST_SRCS	= test_main.c \
            	test_case_basic.c \
               	test_case_numeric.c \
               	test_case_string.c

OBJS	=	$(SRCS:.c=.o)

RM       = rm -f

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

test_basic: $(NAME)
	$(CC) $(CFLAGS) -o test_basic_program test_basic.c -I./includes -L./ -lftprintf
	./test_basic_program
	$(RM) test_basic_program

test_numeric: $(NAME)
	$(CC) $(CFLAGS) -o test_numeric_program test_numeric.c -I./includes -L./ -lftprintf
	./test_numeric_program
	$(RM) test_numeric_program

test_string_program: $(NAME)
	$(CC) $(CFLAGS) -o test_string_program test_string_program.c -I./includes -L./ -lftprintf
	./test_string_program
	$(RM) test_string_program

test: $(NAME)
	$(CC) $(CFLAGS) -o test_program test_main.c -I./includes -L./ -lftprintf
	./test_program
	$(RM) test_program


.PHONY: all clean fclean re
