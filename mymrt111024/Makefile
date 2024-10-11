# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 19:36:12 by tday              #+#    #+#              #
#    Updated: 2024/10/11 19:04:38 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 			:=		miniRT
SRC_DIRS 		:=		src/main src/parsing
OBJ_DIR			:=		obj
INC_DIR 		:=		inc
CC				:=		gcc
CFLAGS			:=		-Wall -Wextra -Werror -O3

# Define source and object files
SRCS			:=		src/main/main.c											\
						src/parsing/file_check.c								\
						src/parsing/get_next_line_utils.c						\
						src/parsing/get_next_line.c								\
						src/parsing/object_utils.c								\
						src/parsing/parse_elements.c							\
						src/parsing/parse_main.c								\
						src/parsing/parse_objects.c								\
						src/parsing/parse_utils.c								\
						src/parsing/utils.c										\
						src/parsing/print_elements.c							\
						src/parsing/print_objects.c						

OBJS			:=		$(SRCS:src/%.c=$(OBJ_DIR)/%.o)
RM				:=		rm -f

# Create object directories
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@$(call check_dir_change,$<)

# Function definition
define check_dir_change
$(eval CUR_DIR := $(patsubst src/%/,%, $(dir $(1))))
$(if $(filter-out $(LAST_DIR),$(CUR_DIR)), @echo "$(GREEN)$(CUR_DIR) functions compiled successfully!$(DEFAULT_COLOUR)")
$(eval LAST_DIR := $(CUR_DIR))
endef

# Colours

DEFAULT_COLOUR	:=		\033[0m
GREEN			:=		\033[1;32m
MAGENTA			:=		\033[1;35m
YELLOW			:=		\033[1;33m
CYAN			:=		\033[1;36m
BLUE			:=		\033[1;34m

# Targets

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
	@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)$(NAME)$(DEFAULT_COLOUR)"

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)Object files deleted.$(DEFAULT_COLOUR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)$(NAME) deleted.$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all clean fclean re
