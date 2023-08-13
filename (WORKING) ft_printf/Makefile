# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atang <atang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 13:43:51 by atang             #+#    #+#              #
#    Updated: 2023/08/13 18:04:12 by atang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = libftprintf.a
INCDIR   = includes
SRCDIR   = sources
TESTDIR  = tests
OBJDIR   = objs

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
sources  = ft_character.c \
           ft_hexadecimal.c \
           ft_integer.c \
           ft_pointer.c \
           ft_printf.c \
           ft_string.c \
           ft_unsigned_decimal.c

test_sources = test_main.c \
               test_case_basic.c \
               test_case_numeric.c \
               test_case_string.c

CFILES   = $(addprefix $(SRCDIR)/, $(sources))
OFILES   = $(addprefix $(OBJDIR)/, $(sources:.c=.o))
TESTCFILES = $(addprefix $(TESTDIR)/, $(test_sources:.c=.o))

RM       = rm -f

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -c $(CFILES) -I./$(INCDIR)
	ar -rcs $(NAME) $(OFILES)

tests: $(TESTCFILES) $(OFILES)
	$(CC) $(CFLAGS) -o tester $(TESTCFILES) $(OFILES) -I./$(INCDIR)

all: $(NAME) tests

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES) $(TESTCFILES)

fclean: clean
	$(RM) $(NAME)
	$(RM) tester

re: fclean all

.PHONY: all clean fclean re tests
