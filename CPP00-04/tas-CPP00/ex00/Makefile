# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 14:03:55 by tday              #+#    #+#              #
#    Updated: 2024/05/04 14:03:55 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			:=		megaphone
SRCS 			:= 		megaphone.cpp
OBJS 			:=		$(SRCS:.cpp=.o)
CPP				:=		c++
CPPFLAGS		:=		-Wall -Wextra -Werror -std=c++98
RM				:=		rm -f

# Colours

DEFAULT_COLOUR	:=		\033[0m
GRAY			:=		\033[1;30m
RED				:=		\033[1;31m
GREEN			:=		\033[1;32m
YELLOW			:=		\033[1;33m
BLUE			:=		\033[1;34m
MAGENTA			:=		\033[1;35m
CYAN			:=		\033[1;36m
WHITE			:=		\033[1;37m

# Recipes

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
				@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)$(NAME)$(DEFAULT_COLOUR)"
				@echo "\n"

$(OBJS):		%.o: %.cpp
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(GREEN)$< compiled.$(DEFAULT_COLOUR)";

clean:			
				@$(RM) $(OBJS)
				@echo "$(MAGENTA)object files deleted.$(DEFAULT_COLOUR)";

fclean: 		
				@$(MAKE) -s clean
				@$(RM) $(NAME)
				@echo "$(YELLOW)$(NAME) deleted.$(DEFAULT_COLOUR)"
				@echo "\n"

re: 			fclean all

.PHONY: 		all clean fclean re
