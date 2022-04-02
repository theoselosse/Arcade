##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = src/sdl.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ../../lib/arcade_sdl2.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) -lSDL2 -lSDL2_image -lSDL2_ttf -fPIC -shared -Wall -Wextra -W $(SRC)
	cp -f $(NAME) ../../lib/graphs

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	rm -f ../../lib/graphs/arcade_sdl2.so

re: fclean all
