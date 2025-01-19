# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 15:02:23 by atang             #+#    #+#              #
#    Updated: 2025/01/19 16:00:33 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= zombie

SRCS 		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS 		= $(SRCS:.cpp=.o)

CPP 		= c++
CPPFLAGS 	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

RST			:= \033[0m
G 			:= \033[1;32m
R			:= \033[1;31m
Y 			:= \033[1;33m

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	echo "$(OBJS)" | tr ' ' '\n' | while read obj; do \
		echo -e "$(Y)$$obj successfully created!$(RST)"; \
	done	
	echo -e "$(G)$(NAME) executable successfully created!$(RST)"

clean:
	@rm -f $(OBJS)
	@echo "$(OBJS)" | tr ' ' '\n' | while read obj; do \
		echo -e "$(Y)$$obj successfully deleted!$(RST)"; \
	done

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(R)$(NAME) executable successfully deleted!$(RST)"

re: fclean all

.PHONY: all, clean, fclean, re