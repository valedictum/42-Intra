ROOT_DIR = $(shell pwd)
LIBFT_DIR = $(ROOT_DIR)/lib/libft
PRINTF_DIR = $(ROOT_DIR)//lib/printf

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBRARY = -lft -lftprintf

SRCS = ./src/*.c
INCS = ./inc
LIBS = ./lib


NAME = push_swap

${NAME}: all

all:
	make -C ${LIBFT_DIR}
	make -C ${PRINTF_DIR}
	${CC} ${CFLAGS} -I ${INCS} ${SRCS} -o ${NAME} -L${LIBFT_DIR} -L${PRINTF_DIR} ${LIBRARY}

clean:
	${RM} ${LIBFT_DIR}/*.o
	${RM} ${PRINTF_DIR}/*.o

fclean: clean
	${RM} ${LIBFT_DIR}/*.a
	${RM} ${PRINTF_DIR}/*.a
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re