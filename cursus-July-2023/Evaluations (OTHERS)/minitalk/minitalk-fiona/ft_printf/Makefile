# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 12:23:41 by fsalimba          #+#    #+#              #
#    Updated: 2023/03/23 12:23:44 by fsalimba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			=	ft_printf.c ft_libft.c ft_put_c_str.c ft_uitoa.c \
					ft_put_ptr.c ft_put_int_uint.c ft_put_hex.c \

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus