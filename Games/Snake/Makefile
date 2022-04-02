##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = src/snake.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ../../lib/arcade_nibbler.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) -fPIC -shared -Wall $(SRC)
	cp -f $(NAME) ../../lib/games

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	rm -f ../../lib/games/arcade_nibbler.so

re: fclean all
