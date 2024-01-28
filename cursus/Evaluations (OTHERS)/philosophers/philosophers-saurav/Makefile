# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasharma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 10:11:12 by sasharma          #+#    #+#              #
#    Updated: 2024/01/20 14:09:24 by sasharma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Philo

CC_Flags= gcc -Wall -Wextra -Werror -I includes\
		  -framework Appkit -g

SOUCRE = src/*.c

all: $(NAME)

OBJ = $(SOURCE:%.c=%.o)

%.o:%.c
	$(CC_Flags) -o $@ -c $<

$(NAME):
	$(CC_Flags) $(SOUCRE) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re

