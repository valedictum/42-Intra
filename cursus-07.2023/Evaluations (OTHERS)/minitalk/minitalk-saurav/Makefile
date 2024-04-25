CFLAGS = -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
		$(CC) $(CFLAGS) client.c util.c -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c util.c -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c
		$(CC) $(CFLAGS) client_bonus.c utils.c -o client_bonus
$(SERVER_BONUS) : server_bonus.c
		$(CC) $(CFLAGS) server_bonus.c utils.c -o server_bonus
fclean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
re: fclean all bonus
