NAME		= animal
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra
RM			= rm -rf
INC			= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/
SRC 		= Animal.cpp WrongAnimal.cpp Dog.cpp Cat.cpp WrongCat.cpp main.cpp

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

.PHONY: 		all clean re