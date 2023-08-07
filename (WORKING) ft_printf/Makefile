# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 13:43:51 by atang             #+#    #+#              #
#    Updated: 2023/08/07 11:28:48 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_filename \
		  ft_filename \
		  ft_filename \

CFILES 	= $(SRCS:%=%.c)
OFILES	= $(SRCS:%=%.o)

RM		= rm -f

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES) -I./
	ar -rcs $(NAME) $(OFILES)

all: $(NAME)

clean:
	$(RM) $(OFILES)

flcean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean flean re