# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 18:47:44 by mclaver-          #+#    #+#              #
#    Updated: 2025/12/03 18:47:45 by mclaver-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

HEADERS = Array.hpp

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
