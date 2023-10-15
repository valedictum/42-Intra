NAME 			= minitalk

SERVER			= server
SERVER_SRC		= server.c
SERVER_OBJ 	= $(SERVER_SRC:.c=.o)

CLIENT			= client
CLIENT_SRC		= client.c
CLIENT_OBJ 	= $(CLIENT_SRC:.c=.o)

PRINTF_DIR		= ft_printf/
PRINTF			= $(PRINTF_DIR)libftprintf.a
PRINTF_MAKE		= make -C $(PRINTF_DIR)

CC 				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror

all: 			$(NAME)

$(NAME): 		$(SERVER) $(CLIENT)

$(SERVER):		$(SERVER_OBJ)
				$(PRINTF_MAKE)
				$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER) $(PRINTF)

$(CLIENT):		$(CLIENT_OBJ)
				$(PRINTF_MAKE)
				$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT) $(PRINTF)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(PRINTF_MAKE) clean
				$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: 		clean
				$(PRINTF_MAKE) fclean
				$(RM) $(SERVER) $(CLIENT)

re: 			fclean all

.PHONY: 		all clean fclean re