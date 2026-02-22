NAME = RPN

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

HEADERS = RPN.hpp

all: $(NAME)

$(NAME): Makefile $(OBJ) $(HEADERS)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
