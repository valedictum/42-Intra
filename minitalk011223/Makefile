# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 19:22:44 by atang             #+#    #+#              #
#    Updated: 2023/12/01 18:56:55 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER      = server
CLIENT      = client
CC          = gcc
RM          = rm -f
AR          = ar
CFLAGS      = -Wall -Wextra -Werror -I$(PRINTF_DIR)/includes -I$(INCS)

ROOT_DIR    = $(shell pwd)
PRINTF_DIR  = $(ROOT_DIR)/libs/printf
INCS        = $(ROOT_DIR)/incs

LIBRARY     = -L$(PRINTF_DIR) -lftprintf

SRC_DIR     = $(ROOT_DIR)/srcs/minitalk
SERVER_SRC  = $(SRC_DIR)/server.c
CLIENT_SRC  = $(SRC_DIR)/client.c

LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFTPRINTF_SRC = $(shell find $(PRINTF_DIR) -name '*.c')
LIBFTPRINTF_OBJ = $(LIBFTPRINTF_SRC:.c=.o)

all: $(LIBFTPRINTF) $(SERVER) $(CLIENT)

$(LIBFTPRINTF): $(LIBFTPRINTF_OBJ)
	$(AR) rcs $@ $^

$(SERVER): $(SERVER_SRC) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $^ -o $(SERVER) $(LIBRARY)

$(CLIENT): $(CLIENT_SRC) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $^ -o $(CLIENT) $(LIBRARY)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBFTPRINTF_OBJ)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
