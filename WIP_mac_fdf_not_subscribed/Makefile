# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 16:56:17 by atang             #+#    #+#              #
#    Updated: 2023/12/17 18:49:41 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fdf

CC = gcc
RM = rm -f
AR = ar
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I$(INCS)

ROOT_DIR = $(shell pwd)
LIBFT_DIR = $(ROOT_DIR)/libs/libft
INCS = $(ROOT_DIR)/incs

LIBRARY = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC_DIR = $(ROOT_DIR)/srcs/
MLX_DIR = $(ROOT_DIR)/minilibx_macos/
FDF_SRC = $(SRC_DIR)/fdf.c

LIBLIBFT = $(LIBFT_DIR)/libft.a
LIBLIBFT_SRC = $(shell find $(LIBFT_DIR) -name '*.c')
LIBLIBFT_OBJ = $(LIBLIBFT_SRC:.c=.o)

all: build_minilibx $(LIBLIBFT) $(FDF)

$(LIBLIBFT): $(LIBLIBFT_OBJ)
	$(AR) rcs $@ $^

$(FDF): $(FDF_SRC) $(LIBLIBFT)
	$(CC) $(CFLAGS) $< -o $@ $(LIBRARY)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

build_minilibx:
	@echo "Building MiniLibX..."
	@cd $(MLX_DIR) && $(MAKE)

fclean_minilibx:
	@echo "Fully cleaning MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) fclean

clean:
	$(RM) $(LIBLIBFT_OBJ)

fclean: clean fclean_minilibx
	$(RM) $(FDF) $(LIBLIBFT)

re: fclean all

.PHONY: all clean fclean re build_minilibx fclean_minilibx