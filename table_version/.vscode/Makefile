# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 16:35:36 by atang             #+#    #+#              #
#    Updated: 2024/03/03 17:39:23 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo
CC				= gcc
RM				= -rm -f
CFLAGS			= -Wall -Wextra -Werror -I(INCS) -g

DEFAULT_COLOUR = \033[0m
RED = \033[1;31m
BLUE = \033[1;34m
GREEN = \033[1;32m
YELLOW = \033[1;33m

ROOT_DIR		= $(shell_pwd)
SRC_DIR			= $(ROOT_DIR)/srcs

SRCS	=	main.c utils.c \

OBJS	= $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
INCS	= $(ROOT_DIR)/INCS

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -I $(INCS) $(OBJS) -o $(NAME)

all:	$(NAME)

$(OBJS):	$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -I $(INCS) $(OBJS) -s $, -o $@

clean:
		$(RM) $(OBJS)
		@echo "Deleted object files."

fclean:	clean
		$(RM) $(NAME)
		@echo "Deleted executable: $(NAME)"

re:	fclean all

.PHONY:	all clean fclean re
