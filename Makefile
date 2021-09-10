NAME=solveur

CC = g++
FLAG = -Wall -Wextra
INCLUDES = -I$(HEADERS_DIR)

HEADERS_LIST =	Cube.H.hpp\
				

HEADERS_DIR = ./include/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_LIST =	main.cpp		\
			Cube.C.cpp

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_LIST = $(patsubst %.cpp, %.o, $(SRC_LIST))
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME):$(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS)  $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@


clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

sani :$(OBJ_DIR) $(OBJ)
	@$(CC) $(CCF) $(FLAGS) $(OBJ) -o $(NAME)

test: all
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re sani
