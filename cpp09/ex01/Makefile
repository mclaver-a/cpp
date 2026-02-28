NAME    = RPN
SRC     = main.cpp RPN.cpp
OBJ     = $(SRC:.cpp=.o)
CXX     = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 #pedantic

RM      = rm -f
HEADERS = RPN.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
