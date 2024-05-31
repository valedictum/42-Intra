# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 00:09:20 by tday              #+#    #+#              #
#    Updated: 2024/05/26 15:40:13 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME 			= phonebook
CC 				= c++
CFLAGS 			= -Wall -Wextra -Werror -std=c++98
SRC_DIR 		= sources
INC_DIR 		= includes
SRC 			= $(SRC_DIR)/main.cpp $(SRC_DIR)/Phonebook.cpp $(SRC_DIR)/Contact.cpp
INC 			= $(INC_DIR)/Phonebook.hpp $(INC_DIR)/Contact.hpp
OBJ				= $(SRC:.cpp=.o)
RM				= rm -f


# Colours
DEFAULT_COLOUR	= \033[0m
GRAY 			= \033[1;30m
RED 			= \033[1;31m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
BLUE 			= \033[1;34m
MAGENTA 		= \033[1;35m
CYAN			= \033[1;36m
WHITE 			= \033[1;37m

# Recipes
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(CYAN)Everything compiled and linked into executable: $(WHITE)$(NAME)$(DEFAULT_COLOUR)"

%.o: %.cpp $(INC)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@for file in $(OBJ); do \
		echo "$(MAGENTA)$$file deleted successfully!$(DEFAULT_COLOUR)"; \
		$(RM) $$file; \
	done

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Deleted executable: $(WHITE)$(NAME).$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all clean fclean re