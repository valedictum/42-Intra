# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 14:38:30 by tday              #+#    #+#              #
#    Updated: 2023/12/19 21:50:26 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= philo
INC_DIR		= includes
SRC_DIR		= sources
SRC_FILES	= main.c dinner.c get_and_set.c init.c inputs.c monitor.c \
			safe_functions.c synchro.c utils.c write.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(SRCS:%.c=%.o)
AR			= ar -rcs
RM			= rm -f
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)

# Colours

DEFAULT_COLOUR = \033[0m
GRAY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

# Recipes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)$(NAME)$(DEFAULT_COLOUR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)local object files deleted.$(DEFAULT_COLOUR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Deleted executable: $(WHITE)$(NAME).$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all clean fclean re