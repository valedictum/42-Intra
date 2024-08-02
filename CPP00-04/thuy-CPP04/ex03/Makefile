NAME 		= amateria
CXX 		= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra
RM			= rm -rf
SRC_DIR		= src/
OBJ_DIR		= obj/
SRC			= AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJ 		= 	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp 
				@mkdir -p $(@D)
				@$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
				@$(RM) $(NAME) $(OBJ_DIR)

re: 			clean all

.PHONY: 		all clean re leaks valgrind_leaks

leaks: re
	@echo "\033[1;33m\nChecking for memory leaks...\033[0m"
	leaks --atExit -- ./$(NAME)

valgrind_leaks: re
	@echo "\033[1;33m\nChecking for memory leaks with valgrind...\033[0m"
	valgrind --leak-check=full ./$(NAME)