# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 14:30:00 by tday              #+#    #+#              #
#    Updated: 2023/09/09 14:30:00 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libft.a
GNL_DIR	= get_next_line
PRF_DIR	= ft_printf
GNL_LIB	= $(GNL_DIR)/libgnl.a
PRF_LIB	= $(PRF_DIR)/libftprintf.a
SRCDIR	= sources
INCDIR	= includes 
SRCFILE = ft_abs.c ft_atoi.c ft_bzero.c ft_calloc.c ft_count_words.c\
		  ft_fabs.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
		  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		  ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		  ft_substr.c ft_tolower.c ft_toupper.c ft_swap.c ft_round_up.c\
		  ft_atolong.c ft_strcmp.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))		    
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR)
AR		= ar -rcs
RM		= rm -f

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

$(NAME): $(OBJS) $(GNL_LIB) $(PRF_LIB)
	@$(AR) $(NAME) $(OBJS) $(GNL_DIR)/$(SRCDIR)/*.o $(PRF_DIR)/$(SRCDIR)/*.o
	@echo "$(CYAN)$(NAME) compiled successfully!$(DEFAULT_COLOUR)"

$(GNL_LIB):
	@$(MAKE) all -s -C $(GNL_DIR)
	@echo "\n"

$(PRF_LIB):
	@$(MAKE) -s -C $(PRF_DIR)
	@echo "\n"

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@$(MAKE) clean -s -C $(GNL_DIR)
	@echo "$(RED)cleaned gnl.$(DEFAULT_COLOUR)"
	@$(MAKE) clean -s -C $(PRF_DIR)
	@echo "$(RED)cleaned ft_printf.$(DEFAULT_COLOUR)"
	@$(RM) $(OBJS)
	@echo "$(RED)cleaned libft.$(DEFAULT_COLOUR)"

fclean: clean
	@$(MAKE) fclean -s -C $(GNL_DIR)
	@echo "$(RED)fcleaned gnl.$(DEFAULT_COLOUR)"
	@$(MAKE) fclean -s -C $(PRF_DIR)
	@echo "$(RED)fcleaned ft_printf.$(DEFAULT_COLOUR)"
	@$(RM) $(NAME)
	@echo "$(RED)fcleaned libft.$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all clean fclean re