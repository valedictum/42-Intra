# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:44:36 by atang             #+#    #+#              #
#    Updated: 2023/09/29 15:18:59 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror -I./libft -I./ft_printf
LIBFTDIR 		= libft/
FT_PRINTFDIR	= ft_printf/
OBJ_DIR 		= obj/
BONUS 			= checker
SRC_DIR 		= srcs/

SRCS	= srcs/push_swap/push_swap.c \
			operations_push.c \
			operations_reverse_rotate.c \
			operations_rotate.c \
        	operations_swap.c \
           	parse_arguments.c \
           	ps_check_utils.c \
           	ps_find_index_utils.c \
			ps_find_utils.c \
			ps_list_utils.c \
			ps_memory_utils.c \
			ps_print_utils.c \
			ps_sort_few.c \
			ps_sort_many.c \
			
OBJS	=	$(SRCS:.c=.o)

RM      = rm -f

INCLUDE	= -L$(LIBFTDIR) -L$(FT_PRINTFDIR) -lft -lft_printf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(FT_PRINTFDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

all: ${NAME}

clean:
	$(RM) $(OBJS)
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(FT_PRINTFDIR) && $(MAKE) fclean

fclean:	clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(FT_PRINTFDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
