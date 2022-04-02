##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = src/pacman.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ../../lib/arcade_pacman.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) -fPIC -shared -Wall $(SRC)
	cp -f $(NAME) ../../lib/games

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	rm -f ../../lib/games/arcade_pacman.so

re: fclean all
