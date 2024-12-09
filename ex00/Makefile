NAME = bureaucrat

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = src/Bureaucrat.cpp

MAIN = main.cpp

OBJ = $(MAIN:.cpp=.o) $(SRC:.cpp=.o)


HEADERS = includes/Bureaucrat.hpp

all : ${NAME}

${NAME}: ${OBJ}
	@echo "Compiling into object files"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled successfuly!"

%.o: %.cpp ${HEADERS}
	@echo "Compiling $< into object file"
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted."

fclean : clean
	@rm -rf ${NAME}
	@echo "Executable deleted."

re:
	@make fclean
	@make
