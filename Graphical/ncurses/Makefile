##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
#

SRC = src/libncurses.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -fPIC -shared

NAME = ../../lib/arcade_ncurses.so

all: $(NAME)

$(NAME): $(OBJ)
	g++ -lncurses -o $(NAME) -Wall $(SRC) $(CXXFLAGS)
	cp -f $(NAME) ../../lib/graphs

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	rm -f ../../lib/graphs/arcade_ncurses.so

re: fclean all

.cpp.o: