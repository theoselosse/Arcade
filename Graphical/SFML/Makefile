##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = src/SFML_Lib.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ../../lib/arcade_sfml.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system -fPIC -shared -Wall -Wextra -W $(SRC)
	cp -f $(NAME) ../../lib/graphs

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	rm -f ../../lib/graphs/arcade_sfml.so

re: fclean all
