# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 19:22:44 by atang             #+#    #+#              #
#    Updated: 2023/11/26 21:10:41 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			= server
CLIENT			= client
CC				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror -I$(PRINTF_DIR) -I$(INCS)
LIBRARY 		= -L$(PRINTF_DIR) -lftprintf

ROOT_DIR 		= $(shell pwd)
PRINTF_DIR 		= $(ROOT_DIR)/libs/printf
SRC_DIR 		= $(ROOT_DIR)/srcs/minitalk

SRCS	= 	client.c \
			server.c \
		
OBJS	=	$(SRCS:.c=.o)

INCS = $(ROOT_DIR)/incs

$(NAME): all

all:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -I $(INCS) -I $(PRINTF_DIR) $(addprefix $(SRC_DIR)/, $(SRCS)) -o $(NAME) $(LIBRARY)
	@gcc $(FLAGS) server.c -o $(SERVER)
	@gcc $(FLAGS) client.c -o $(CLIENT)
	@echo "Server And Client Are Ready!"
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
