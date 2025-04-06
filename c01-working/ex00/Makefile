# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 15:02:23 by atang             #+#    #+#              #
#    Updated: 2025/01/22 22:53:38 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME 		= zombie
CPP 		= c++
CPPFLAGS 	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

# Sources
SRCS 		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS 		= $(SRCS:.cpp=.o)

# Colours
RST			:= \033[0m
G 			:= \033[1;32m
R			:= \033[1;31m
Y 			:= \033[1;33m

.SILENT:

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	echo "$(OBJS)" | tr ' ' '\n' | while read obj; do \
		echo -e "$(Y)$$obj successfully created!$(RST)"; \
	done	
	echo -e "$(G)$(NAME) executable successfully created!$(RST)"

clean:
	@rm -f $(OBJS)
	if [ -n "$(OBJS)" ]; then \
		echo "$(OBJS)" | tr ' ' '\n' | while read obj; do \
			echo -e "$(Y)$$obj successfully deleted!$(RST)"; \
		done; \
	fi
	
fclean: clean
	if [ -f $(NAME) ]; then \
		echo -e "$(R)$(NAME) executable successfully deleted!$(RST)"; \
		rm -f $(NAME); \
	fi
	
re: fclean all

.PHONY: all clean fclean re