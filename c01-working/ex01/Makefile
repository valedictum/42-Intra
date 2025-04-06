# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 15:08:19 by atang             #+#    #+#              #
#    Updated: 2025/03/29 15:08:19 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME 		= zombies
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

# Sources
SRCS		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS		= $(SRCS:.cpp=.o)

# Colours
RST = "\033[0m"		
G 	= "\033[32m"     
R 	= "\033[31m"
Y	= "\033[33m"

.SILENT:

# Rules
all:  $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	echo "$(OBJS)" | tr ' ' '\n' | while read obj; do \
		echo $Y"$$obj successfully created!"$(RST); \
	done	
	echo $G" $(NAME) executable successfully created!"$(RST)

clean:
	@rm -f $(OBJS)
	if [ -n "$(OBJS)" ]; then \
		echo "$(OBJS)" | tr ' ' '\n' | while read obj; do \
			echo $Y"$$obj successfully deleted!"$(RST); \
		done; \
	fi
	
fclean: clean
	if [ -f $(NAME) ]; then \
		echo $R"  $(NAME) executable successfully deleted!"$(RST); \
		rm -f $(NAME); \
	fi
	
re: fclean all

.PHONY: all clean fclean re



