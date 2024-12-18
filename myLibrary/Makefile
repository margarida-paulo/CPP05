NAME = myLib.a

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = MyLib.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = MyLib.hpp

all: ${NAME}

${NAME}:${OBJ}
	ar rcs ${NAME} ${OBJ}
	@echo "Library compiled successfully!"

%.o: %.cpp ${HEADERS}
	${CC} ${FLAGS} -c $< -o $@

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted."

fclean: clean
	@rm -rf ${NAME}
	@echo "Library deleted."

re: fclean all