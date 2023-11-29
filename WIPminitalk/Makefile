# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sentry <sentry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 19:22:44 by atang             #+#    #+#              #
#    Updated: 2023/11/29 06:32:29 by sentry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER      = server
CLIENT      = client
CC          = gcc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror -I$(PRINTF_DIR) -I$(INCS)

ROOT_DIR    = $(shell pwd)
PRINTF_DIR  = $(ROOT_DIR)/libs/printf
INCS        = $(ROOT_DIR)/incs

LIBRARY     = -L$(PRINTF_DIR) -lftprintf

SRC_DIR     = $(ROOT_DIR)/srcs/minitalk
SERVER_SRC  = $(SRC_DIR)/server.c
CLIENT_SRC  = $(SRC_DIR)/client.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) $^ -o $(SERVER) $(LIBRARY)

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $^ -o $(CLIENT) $(LIBRARY)
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
