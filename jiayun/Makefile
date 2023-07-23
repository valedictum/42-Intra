# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jong <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 11:54:36 by jong              #+#    #+#              #
#    Updated: 2023/07/19 23:26:32 by jong             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= 	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
			ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
			ft_memmove ft_memset ft_putchar_fd ft_putendl_fd \
			ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup \
			ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen \
			ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim \
			ft_substr ft_tolower ft_toupper

CFILES  = $(SRCS)

OFILES  = $(SRCS:.c=.o)

RM      = rm -f

$(NAME): $(OFILES)
    ar -rcs $(NAME) $(OFILES)

all: $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    $(RM) $(OFILES)

fclean: clean
    $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
