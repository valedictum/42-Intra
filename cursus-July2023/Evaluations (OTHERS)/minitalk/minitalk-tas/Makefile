# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 21:22:08 by tday              #+#    #+#              #
#    Updated: 2023/11/03 23:31:16 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CNAME		= client
SNAME		= server
LFT_DIR		= libft
LFT_LIB		= $(LFT_DIR)/libft.a
INC_DIR		= includes
SRCS_CLIENT	= client.c
SRCS_SERVER	= server.c
OBJS_CLIENT	= $(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER	= $(SRCS_SERVER:%.c=%.o)
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

all: $(CNAME) $(SNAME)

$(CNAME): $(LFT_LIB) $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LFT_DIR) -lft -o $(CNAME)
	@echo "$(CYAN)$(CNAME) compiled and linked into executable: $(BLUE)$(CNAME)$(DEFAULT_COLOUR)"

$(SNAME): $(LFT_LIB) $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LFT_DIR) -lft -o $(SNAME)
	@echo "$(CYAN)$(SNAME) compiled and linked into executable: $(BLUE)$(SNAME)$(DEFAULT_COLOUR)"

$(LFT_LIB):
	@$(MAKE) -s -C $(LFT_DIR)
	@echo "\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@echo "$(MAGENTA)Object files deleted.$(DEFAULT_COLOUR)"
	@$(MAKE) clean -s -C $(LFT_DIR)
	@echo "$(RED)cleaned all libraries.$(DEFAULT_COLOUR)"

fclean: clean
	@$(MAKE) fclean -s -C $(LFT_DIR)
	@echo "$(RED)fcleaned all libraries.$(DEFAULT_COLOUR)"
	@$(RM) $(CNAME) $(SNAME)
	@echo "$(YELLOW)Deleted executables: $(WHITE)$(CNAME) & $(SNAME).$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all clean fclean re