# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 20:54:51 by mclaver-          #+#    #+#              #
#    Updated: 2025/11/18 20:54:53 by mclaver-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

SRC = ScalarConvert.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

HEADERS = ScalarConvert.hpp

all: $(NAME) $(BONUS)

$(NAME): Makefile $(OBJ) $(HEADERS)
	@$(COMPILE) $(OBJ) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY = all clean fclean re
